(() => {
  const INITIAL_VALUES = [3, 1, 4, 1, 5, 9, 2, 6];
  const WIDTH = 900;
  const HEIGHT = 410;
  const MARGIN = { top: 36, right: 28, bottom: 34, left: 28 };
  const LEAF_GAP = 14;
  const NODE_WIDTH = 96;
  const NODE_HEIGHT = 48;
  const LEVEL_GAP = 88;

  function formatDelta(delta) {
    return delta >= 0 ? `+${delta}` : `${delta}`;
  }

  function intervalLabel(node) {
    return `[${node.l}, ${node.r})`;
  }

  function buildTree(values, l = 0, r = values.length, depth = 0) {
    const node = {
      id: `${l}-${r}`,
      l,
      r,
      depth,
      sum: values.slice(l, r).reduce((acc, value) => acc + value, 0),
      lazy: 0,
      left: null,
      right: null,
    };

    if (r - l > 1) {
      const m = Math.floor((l + r) / 2);
      node.left = buildTree(values, l, m, depth + 1);
      node.right = buildTree(values, m, r, depth + 1);
    }

    return node;
  }

  function traverse(node, visit) {
    visit(node);
    if (node.left) {
      traverse(node.left, visit);
    }
    if (node.right) {
      traverse(node.right, visit);
    }
  }

  function assignLayout(root) {
    const leaves = [];
    traverse(root, (node) => {
      if (!node.left) {
        leaves.push(node);
      }
    });

    const innerWidth = WIDTH - MARGIN.left - MARGIN.right;
    const cellWidth = (innerWidth - LEAF_GAP * (leaves.length - 1)) / leaves.length;
    const leafCenter = (index) => MARGIN.left + index * (cellWidth + LEAF_GAP) + cellWidth / 2;

    leaves.forEach((leaf, index) => {
      leaf.x = leafCenter(index);
      leaf.y = MARGIN.top + leaf.depth * LEVEL_GAP;
    });

    function backfill(node) {
      if (!node.left) {
        return;
      }
      backfill(node.left);
      backfill(node.right);
      node.x = (node.left.x + node.right.x) / 2;
      node.y = MARGIN.top + node.depth * LEVEL_GAP;
    }

    backfill(root);
  }

  function applyNode(node, delta, trace) {
    node.sum += delta * (node.r - node.l);
    node.lazy += delta;
    trace.tagged.add(node.id);
    trace.messages.push(`apply ${formatDelta(delta)} to ${intervalLabel(node)}`);
  }

  function pushNode(node, trace) {
    if (!node.left || node.lazy === 0) {
      return;
    }
    const pending = node.lazy;
    trace.pushed.add(node.id);
    trace.messages.push(`push ${formatDelta(pending)} from ${intervalLabel(node)} to its children`);
    applyNode(node.left, pending, trace);
    applyNode(node.right, pending, trace);
    node.lazy = 0;
  }

  function pullNode(node, trace) {
    if (!node.left) {
      return;
    }
    node.sum = node.left.sum + node.right.sum;
    trace.pulled.add(node.id);
    trace.messages.push(`pull ${intervalLabel(node)} from its children`);
  }

  function rangeAdd(node, ql, qr, delta, trace) {
    trace.visited.add(node.id);
    if (qr <= node.l || node.r <= ql) {
      return;
    }
    if (ql <= node.l && node.r <= qr) {
      trace.full.add(node.id);
      applyNode(node, delta, trace);
      return;
    }
    trace.partial.add(node.id);
    pushNode(node, trace);
    rangeAdd(node.left, ql, qr, delta, trace);
    rangeAdd(node.right, ql, qr, delta, trace);
    pullNode(node, trace);
  }

  function rangeSum(node, ql, qr, trace) {
    trace.visited.add(node.id);
    if (qr <= node.l || node.r <= ql) {
      return 0;
    }
    if (ql <= node.l && node.r <= qr) {
      trace.full.add(node.id);
      trace.used.add(node.id);
      return node.sum;
    }
    trace.partial.add(node.id);
    pushNode(node, trace);
    return rangeSum(node.left, ql, qr, trace) + rangeSum(node.right, ql, qr, trace);
  }

  function collectActiveLazy(node, output) {
    if (node.lazy !== 0) {
      output.push(`${intervalLabel(node)}:${formatDelta(node.lazy)}`);
    }
    if (node.left) {
      collectActiveLazy(node.left, output);
      collectActiveLazy(node.right, output);
    }
  }

  function renderArray(root, values, ql = null, qr = null) {
    const host = root.querySelector('[data-role="array-strip"]');
    host.innerHTML = values
      .map((value, index) => {
        const classes = ["visual-cell"];
        if (ql !== null && qr !== null && ql <= index && index < qr) {
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

  function renderTree(root, state, trace) {
    const host = root.querySelector('[data-role="canvas"]');
    host.innerHTML = "";

    const svg = d3
      .select(host)
      .append("svg")
      .attr("viewBox", `0 0 ${WIDTH} ${HEIGHT}`)
      .attr("class", "lazy-tree-svg")
      .attr("role", "img")
      .attr("aria-label", "Lazy segment tree visualizer");

    const links = [];
    traverse(state.tree, (node) => {
      if (node.left) {
        links.push({ source: node, target: node.left });
        links.push({ source: node, target: node.right });
      }
    });

    svg
      .append("g")
      .attr("class", "lazy-tree-links")
      .selectAll("line")
      .data(links)
      .enter()
      .append("line")
      .attr("class", "lazy-tree-link")
      .attr("x1", (d) => d.source.x)
      .attr("y1", (d) => d.source.y + NODE_HEIGHT / 2)
      .attr("x2", (d) => d.target.x)
      .attr("y2", (d) => d.target.y - NODE_HEIGHT / 2);

    const nodes = [];
    traverse(state.tree, (node) => nodes.push(node));

    const groups = svg
      .append("g")
      .attr("class", "lazy-tree-nodes")
      .selectAll("g")
      .data(nodes)
      .enter()
      .append("g")
      .attr("transform", (d) => `translate(${d.x}, ${d.y})`);

    groups
      .append("rect")
      .attr("class", (d) => {
        const classes = ["lazy-tree-node"];
        if (trace.full.has(d.id)) {
          classes.push("is-full");
        } else if (trace.partial.has(d.id)) {
          classes.push("is-partial");
        }
        if (trace.pushed.has(d.id)) {
          classes.push("was-pushed");
        }
        if (trace.pulled.has(d.id)) {
          classes.push("was-pulled");
        }
        if (d.lazy !== 0) {
          classes.push("has-lazy");
        }
        return classes.join(" ");
      })
      .attr("x", -NODE_WIDTH / 2)
      .attr("y", -NODE_HEIGHT / 2)
      .attr("rx", 15)
      .attr("width", NODE_WIDTH)
      .attr("height", NODE_HEIGHT);

    groups
      .append("text")
      .attr("class", "lazy-tree-interval")
      .attr("text-anchor", "middle")
      .attr("y", -6)
      .text((d) => intervalLabel(d));

    groups
      .append("text")
      .attr("class", "lazy-tree-sum")
      .attr("text-anchor", "middle")
      .attr("y", 12)
      .text((d) => `sum ${d.sum}`);

    groups
      .filter((d) => d.lazy !== 0)
      .append("text")
      .attr("class", "lazy-tree-tag")
      .attr("text-anchor", "middle")
      .attr("y", 29)
      .text((d) => `lazy ${formatDelta(d.lazy)}`);
  }

  function makeTrace(kind) {
    return {
      kind,
      visited: new Set(),
      full: new Set(),
      partial: new Set(),
      tagged: new Set(),
      pushed: new Set(),
      pulled: new Set(),
      used: new Set(),
      messages: [],
    };
  }

  function renderSummary(root, state, trace, resultText, noteText) {
    const activeLazy = [];
    collectActiveLazy(state.tree, activeLazy);

    root.querySelector('[data-role="invariant"]').textContent =
      trace.kind === "update"
        ? "A fully covered node can absorb the whole range add immediately. Only partial overlap forces push + recurse + pull."
        : "During query, any partially overlapped node must push before its children are inspected. Fully covered nodes can answer directly.";

    root.querySelector('[data-role="visited"]').textContent =
      `Visited: ${Array.from(trace.visited).map((id) => `[${id.replace("-", ", ")})`).join(" -> ") || "-"}`;

    root.querySelector('[data-role="lazy-events"]').textContent =
      `Tagged nodes: ${Array.from(trace.tagged).map((id) => `[${id.replace("-", ", ")})`).join(", ") || "-"} | Pushed: ${Array.from(trace.pushed).map((id) => `[${id.replace("-", ", ")})`).join(", ") || "-"} | Pulled: ${Array.from(trace.pulled).map((id) => `[${id.replace("-", ", ")})`).join(", ") || "-"}`;

    root.querySelector('[data-role="result"]').textContent = resultText;
    root.querySelector('[data-role="note"]').textContent = noteText;
    root.querySelector('[data-role="active-lazy"]').textContent =
      activeLazy.length ? activeLazy.join(" | ") : "No pending lazy tags.";
  }

  function reset(root, state) {
    state.values = [...INITIAL_VALUES];
    state.tree = buildTree(state.values);
    assignLayout(state.tree);
    renderArray(root, state.values);
    renderTree(root, state, makeTrace("idle"));
    root.querySelector('[data-role="invariant"]').textContent =
      "Each node summary is correct for its full interval. Lazy tags mean the parent is already correct while children still owe work.";
    root.querySelector('[data-role="visited"]').textContent = "-";
    root.querySelector('[data-role="lazy-events"]').textContent = "-";
    root.querySelector('[data-role="active-lazy"]').textContent = "No pending lazy tags.";
    root.querySelector('[data-role="result"]').textContent = "-";
    root.querySelector('[data-role="note"]').textContent =
      "Default demo: first apply add [2, 6) += 3, then query [3, 5) to watch push move pending work downward.";
  }

  function runUpdate(root, state) {
    const l = Number(root.querySelector('[data-role="update-l"]').value);
    const r = Number(root.querySelector('[data-role="update-r"]').value);
    const delta = Number(root.querySelector('[data-role="update-delta"]').value);
    if (!(l < r)) {
      root.querySelector('[data-role="result"]').textContent = "Choose update l < r.";
      return;
    }

    for (let i = l; i < r; i += 1) {
      state.values[i] += delta;
    }

    const trace = makeTrace("update");
    rangeAdd(state.tree, l, r, delta, trace);
    renderArray(root, state.values, l, r);
    renderTree(root, state, trace);
    renderSummary(
      root,
      state,
      trace,
      `Applied add([${l}, ${r}), ${formatDelta(delta)})`,
      "Blue nodes were fully covered. Purple-outline nodes had to push before descending. Green-outline nodes were pulled back from their children.",
    );
  }

  function runQuery(root, state) {
    const l = Number(root.querySelector('[data-role="query-l"]').value);
    const r = Number(root.querySelector('[data-role="query-r"]').value);
    if (!(l < r)) {
      root.querySelector('[data-role="result"]').textContent = "Choose query l < r.";
      return;
    }

    const trace = makeTrace("query");
    const result = rangeSum(state.tree, l, r, trace);
    renderArray(root, state.values, l, r);
    renderTree(root, state, trace);
    renderSummary(
      root,
      state,
      trace,
      `sum([${l}, ${r})) = ${result}`,
      "If a query partially overlaps a node with pending work, the tag must be pushed before the query can trust the children individually.",
    );
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const state = {};
    root.querySelector('[data-role="run-update"]').addEventListener("click", () => {
      runUpdate(root, state);
    });
    root.querySelector('[data-role="run-query"]').addEventListener("click", () => {
      runQuery(root, state);
    });
    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(root, state);
    });

    reset(root, state);
  }

  function boot() {
    document.querySelectorAll("[data-lazy-segment-tree-visualizer]").forEach(initOne);
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
