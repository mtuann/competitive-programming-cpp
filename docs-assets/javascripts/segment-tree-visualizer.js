(() => {
  const INITIAL_VALUES = [2, 1, 3, 4, 5, 7, 6, 8];

  function formatIntervalId(id) {
    const [l, r] = id.split("-");
    return `[${l}, ${r})`;
  }

  function buildTree(values) {
    const levels = [[], [], [], []];

    function dfs(l, r, depth) {
      const sum = values.slice(l, r).reduce((acc, value) => acc + value, 0);
      const id = `${l}-${r}`;
      const node = { id, l, r, sum, depth };
      levels[depth].push(node);
      if (r - l > 1) {
        const m = Math.floor((l + r) / 2);
        node.left = dfs(l, m, depth + 1);
        node.right = dfs(m, r, depth + 1);
      }
      return node;
    }

    return { root: dfs(0, values.length, 0), levels };
  }

  function collectQuery(node, ql, qr, full, partial) {
    if (node.r <= ql || qr <= node.l) {
      return 0;
    }
    if (ql <= node.l && node.r <= qr) {
      full.add(node.id);
      return node.sum;
    }
    partial.add(node.id);
    return collectQuery(node.left, ql, qr, full, partial) + collectQuery(node.right, ql, qr, full, partial);
  }

  function pathToLeaf(node, index, path) {
    path.push(node.id);
    if (node.r - node.l === 1) {
      return;
    }
    if (index < node.left.r) {
      pathToLeaf(node.left, index, path);
    } else {
      pathToLeaf(node.right, index, path);
    }
  }

  function renderArray(root, values, highlightIndex = null) {
    const host = root.querySelector('[data-role="array-strip"]');
    host.innerHTML = values
      .map((value, index) => {
        const classes = ["visual-cell"];
        if (index === highlightIndex) {
          classes.push("is-highlight");
        }
        return `
          <div class="${classes.join(" ")}">
            <small>a[${index}]</small>
            <strong>${value}</strong>
          </div>
        `;
      })
      .join("");
  }

  function renderTree(root, levels, full = new Set(), partial = new Set(), path = new Set()) {
    const host = root.querySelector('[data-role="tree"]');
    host.innerHTML = levels
      .map((row) => {
        const rowClass = `visual-tree-row visual-tree-row--${row.length}`;
        const rowHtml = row
          .map((node) => {
            const classes = ["visual-cell", "visual-tree-node"];
            if (path.has(node.id)) {
              classes.push("is-highlight");
            } else if (full.has(node.id)) {
              classes.push("is-highlight");
            } else if (partial.has(node.id)) {
              classes.push("is-secondary");
            }
            return `
              <div class="${classes.join(" ")}">
                <small>[${node.l}, ${node.r})</small>
                <strong>${node.sum}</strong>
              </div>
            `;
          })
          .join("");
        return `<div class="${rowClass}">${rowHtml}</div>`;
      })
      .join("");
  }

  function rebuild(root, state, options = {}) {
    state.tree = buildTree(state.values);
    renderArray(root, state.values, options.highlightIndex ?? null);
    renderTree(
      root,
      state.tree.levels,
      options.full ?? new Set(),
      options.partial ?? new Set(),
      options.path ?? new Set(),
    );
  }

  function reset(root, state) {
    state.values = [...INITIAL_VALUES];
    rebuild(root, state);
    root.querySelector('[data-role="invariant"]').textContent =
      "Each node stores the aggregate for exactly one interval [L, R).";
    root.querySelector('[data-role="path"]').textContent = "-";
    root.querySelector('[data-role="result"]').textContent = "-";
    root.querySelector('[data-role="note"]').textContent =
      "Query to see canonical decomposition, then update one leaf to see the leaf-to-root repair path.";
  }

  function runQuery(root, state) {
    const l = Number(root.querySelector('[data-role="query-l"]').value);
    const r = Number(root.querySelector('[data-role="query-r"]').value);
    if (!(l < r)) {
      root.querySelector('[data-role="result"]').textContent = "Choose l < r.";
      return;
    }
    const full = new Set();
    const partial = new Set();
    const result = collectQuery(state.tree.root, l, r, full, partial);
    rebuild(root, state, { full, partial });
    root.querySelector('[data-role="invariant"]').textContent =
      "Range query keeps only fully covered node intervals and splits partial overlaps until the target is tiled.";
    root.querySelector('[data-role="path"]').textContent =
      `Canonical pieces: ${Array.from(full).map((id) => formatIntervalId(id)).join(" + ")}`;
    root.querySelector('[data-role="result"]').textContent = `sum([${l}, ${r})) = ${result}`;
    root.querySelector('[data-role="note"]').textContent =
      "Blue nodes are fully used in the answer; amber nodes were only stepping stones that had to split further.";
  }

  function runUpdate(root, state) {
    const idx = Number(root.querySelector('[data-role="update-index"]').value);
    const nextValue = Number(root.querySelector('[data-role="update-value"]').value);
    state.values[idx] = nextValue;
    const path = [];
    pathToLeaf(state.tree.root, idx, path);
    rebuild(root, state, { path: new Set(path), highlightIndex: idx });
    root.querySelector('[data-role="invariant"]').textContent =
      "A point update changes one leaf, so only the ancestors on that one leaf-to-root path must be recomputed.";
    root.querySelector('[data-role="path"]').textContent = `Repair path: ${path.join(" -> ")}`;
    root.querySelector('[data-role="result"]').textContent = `set(${idx}, ${nextValue})`;
    root.querySelector('[data-role="note"]').textContent =
      "Every node off that path still represents the same subarray, so it stays correct automatically.";
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";
    const state = {};

    root.querySelector('[data-role="run-query"]').addEventListener("click", () => {
      runQuery(root, state);
    });
    root.querySelector('[data-role="run-update"]').addEventListener("click", () => {
      runUpdate(root, state);
    });
    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(root, state);
    });

    reset(root, state);
  }

  function boot() {
    document.querySelectorAll("[data-segment-tree-visualizer]").forEach(initOne);
  }

  if (typeof window.document$ !== "undefined" && typeof window.document$.subscribe === "function") {
    window.document$.subscribe(boot);
  }

  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", boot, { once: true });
  } else {
    boot();
  }
})();
