(() => {
  const INITIAL_VALUES = [2, 1, 3, 4, 5, 7, 6, 8];

  function lowbit(x) {
    return x & -x;
  }

  function buildBit(values) {
    const n = values.length;
    const bit = Array(n + 1).fill(0);
    for (let i = 1; i <= n; i += 1) {
      bit[i] += values[i - 1];
      const j = i + lowbit(i);
      if (j <= n) {
        bit[j] += bit[i];
      }
    }
    return bit;
  }

  function prefixTrace(bit, r) {
    let x = r;
    let sum = 0;
    const path = [];
    const blocks = [];
    while (x > 0) {
      path.push(x);
      const left = x - lowbit(x) + 1;
      blocks.push(`[${left}, ${x}]`);
      sum += bit[x];
      x -= lowbit(x);
    }
    return { path, blocks, sum };
  }

  function updateTrace(n, idx) {
    let x = idx;
    const path = [];
    while (x <= n) {
      path.push(x);
      x += lowbit(x);
    }
    return path;
  }

  function renderArray(root, values, highlightIndex) {
    const host = root.querySelector('[data-role="array-strip"]');
    host.innerHTML = values
      .map((value, index) => {
        const css = index + 1 === highlightIndex ? "visual-cell is-highlight" : "visual-cell";
        return `
          <div class="${css}">
            <small>a[${index + 1}]</small>
            <strong>${value}</strong>
          </div>
        `;
      })
      .join("");
  }

  function renderBit(root, bit, path = [], covered = []) {
    const host = root.querySelector('[data-role="bit-strip"]');
    host.innerHTML = bit
      .slice(1)
      .map((value, idxZero) => {
        const idx = idxZero + 1;
        const left = idx - lowbit(idx) + 1;
        const classes = ["visual-cell"];
        if (path.includes(idx)) {
          classes.push("is-highlight");
        }
        if (!path.includes(idx) && covered.includes(idx)) {
          classes.push("is-secondary");
        }
        return `
          <div class="${classes.join(" ")}">
            <small>bit[${idx}]</small>
            <strong>${value}</strong>
            <code>[${left}, ${idx}]</code>
          </div>
        `;
      })
      .join("");
  }

  function reset(root, state) {
    state.values = [...INITIAL_VALUES];
    state.bit = buildBit(state.values);
    renderArray(root, state.values, null);
    renderBit(root, state.bit);
    root.querySelector('[data-role="invariant"]').textContent =
      "Each bit[i] stores the suffix block [i - lowbit(i) + 1, i].";
    root.querySelector('[data-role="path"]').textContent = "-";
    root.querySelector('[data-role="result"]').textContent = "-";
    root.querySelector('[data-role="note"]').textContent =
      "Try a prefix query first, then a point update, and watch how the touched Fenwick blocks differ.";
  }

  function runPrefix(root, state) {
    const r = Number(root.querySelector('[data-role="prefix-index"]').value);
    const trace = prefixTrace(state.bit, r);
    renderArray(root, state.values, null);
    renderBit(root, state.bit, trace.path);
    root.querySelector('[data-role="invariant"]').textContent =
      "Prefix query repeatedly strips the rightmost Fenwick block until the index reaches 0.";
    root.querySelector('[data-role="path"]').textContent =
      `Visited nodes: ${trace.path.join(" -> ")} | Covered blocks: ${trace.blocks.join(" + ")}`;
    root.querySelector('[data-role="result"]').textContent =
      `prefix(${r}) = ${trace.sum}`;
    root.querySelector('[data-role="note"]').textContent =
      "A range sum [l, r] is just prefix(r) - prefix(l - 1).";
  }

  function runUpdate(root, state) {
    const idx = Number(root.querySelector('[data-role="update-index"]').value);
    const delta = Number(root.querySelector('[data-role="update-delta"]').value);
    const path = updateTrace(state.values.length, idx);
    state.values[idx - 1] += delta;
    state.bit = buildBit(state.values);
    renderArray(root, state.values, idx);
    renderBit(root, state.bit, path);
    const sign = delta >= 0 ? "+" : "";
    root.querySelector('[data-role="invariant"]').textContent =
      "Point update climbs through every larger cached block whose interval still contains the changed index.";
    root.querySelector('[data-role="path"]').textContent =
      `Touched nodes: ${path.join(" -> ")}`;
    root.querySelector('[data-role="result"]').textContent =
      `Applied add(${idx}, ${sign}${delta})`;
    root.querySelector('[data-role="note"]').textContent =
      `Only a[${idx}] changed directly, but every Fenwick node on that climb had to absorb the same delta.`;
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";
    const state = {};

    root.querySelector('[data-role="run-prefix"]').addEventListener("click", () => {
      runPrefix(root, state);
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
    document.querySelectorAll("[data-fenwick-visualizer]").forEach(initOne);
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
