(() => {
  const INITIAL_VALUES = {
    1: 5,
    2: 3,
    3: 4,
    4: 2,
    5: 1,
    6: 6,
    7: 7,
    8: 8,
  };

  const CHILDREN = {
    1: [2, 3],
    2: [4, 5],
    3: [6, 7],
    4: [],
    5: [],
    6: [8],
    7: [],
    8: [],
  };

  const ROOT = 1;
  const WIDTH = 900;
  const HEIGHT = 320;
  const LEVEL_GAP = 86;
  const SIBLING_GAP = 86;

  function cloneValues() {
    return { ...INITIAL_VALUES };
  }

  function buildHierarchy(values, nodeId = ROOT) {
    return {
      id: nodeId,
      value: values[nodeId],
      children: CHILDREN[nodeId].map((childId) => buildHierarchy(values, childId)),
    };
  }

  function computeEuler(values) {
    const tin = {};
    const tout = {};
    const order = [];
    const subtreeNodes = {};

    function dfs(u) {
      tin[u] = order.length;
      order.push(u);
      const nodes = [u];
      for (const v of CHILDREN[u]) {
        nodes.push(...dfs(v));
      }
      tout[u] = order.length;
      subtreeNodes[u] = nodes;
      return nodes;
    }

    dfs(ROOT);
    return { tin, tout, order, subtreeNodes };
  }

  function subtreeSum(state, u) {
    const nodes = state.euler.subtreeNodes[u];
    return nodes.reduce((acc, nodeId) => acc + state.values[nodeId], 0);
  }

  function renderFlat(root, state) {
    const host = root.querySelector('[data-role="flat-strip"]');
    const focusNode = state.focusNode;
    const ql = focusNode !== null ? state.euler.tin[focusNode] : null;
    const qr = focusNode !== null ? state.euler.tout[focusNode] : null;
    const updatePos = state.lastUpdatedNode !== null ? state.euler.tin[state.lastUpdatedNode] : null;

    host.innerHTML = state.euler.order
      .map((nodeId, index) => {
        const classes = ["visual-cell"];
        if (ql !== null && ql <= index && index < qr) {
          classes.push("is-highlight");
        }
        if (updatePos === index) {
          classes.push("is-secondary");
        }
        return `
          <div class="${classes.join(" ")}">
            <small>flat[${index}] = node ${nodeId}</small>
            <strong>${state.values[nodeId]}</strong>
            <code>tin=${state.euler.tin[nodeId]}</code>
          </div>
        `;
      })
      .join("");
  }

  function renderTree(root, state) {
    const host = root.querySelector('[data-role="canvas"]');
    host.innerHTML = "";

    const hierarchy = d3.hierarchy(buildHierarchy(state.values));
    const treeLayout = d3.tree().nodeSize([SIBLING_GAP, LEVEL_GAP]);
    treeLayout(hierarchy);

    const nodes = hierarchy.descendants();
    const links = hierarchy.links();

    const minX = d3.min(nodes, (node) => node.x);
    const maxX = d3.max(nodes, (node) => node.x);
    const offsetX = (WIDTH - (maxX - minX)) / 2 - minX;

    const svg = d3
      .select(host)
      .append("svg")
      .attr("viewBox", `0 0 ${WIDTH} ${HEIGHT}`)
      .attr("class", "euler-tour-svg")
      .attr("role", "img")
      .attr("aria-label", "Euler tour subtree flattening visualizer");

    const g = svg.append("g").attr("transform", `translate(${offsetX}, 34)`);

    g.append("g")
      .attr("class", "euler-tour-links")
      .selectAll("line")
      .data(links)
      .enter()
      .append("line")
      .attr("class", "euler-tour-link")
      .attr("x1", (d) => d.source.x)
      .attr("y1", (d) => d.source.y)
      .attr("x2", (d) => d.target.x)
      .attr("y2", (d) => d.target.y);

    const focusSet =
      state.focusNode === null ? new Set() : new Set(state.euler.subtreeNodes[state.focusNode]);

    const groups = g
      .append("g")
      .attr("class", "euler-tour-nodes")
      .selectAll("g")
      .data(nodes)
      .enter()
      .append("g")
      .attr("transform", (d) => `translate(${d.x}, ${d.y})`);

    groups
      .append("circle")
      .attr("class", (d) => {
        const classes = ["euler-tour-node"];
        if (focusSet.has(d.data.id)) {
          classes.push("is-subtree");
        }
        if (state.lastUpdatedNode === d.data.id) {
          classes.push("is-updated");
        }
        if (state.focusNode === d.data.id) {
          classes.push("is-focus");
        }
        return classes.join(" ");
      })
      .attr("r", 23);

    groups
      .append("text")
      .attr("class", "euler-tour-node-label")
      .attr("text-anchor", "middle")
      .attr("y", -2)
      .text((d) => d.data.id);

    groups
      .append("text")
      .attr("class", "euler-tour-node-value")
      .attr("text-anchor", "middle")
      .attr("y", 14)
      .text((d) => d.data.value);

    groups
      .append("text")
      .attr("class", "euler-tour-node-time")
      .attr("text-anchor", "middle")
      .attr("y", 42)
      .text((d) => `[${state.euler.tin[d.data.id]}, ${state.euler.tout[d.data.id]})`);
  }

  function renderSummary(root, state, actionText) {
    const focusNode = state.focusNode;
    const subtreeNodes = focusNode !== null ? state.euler.subtreeNodes[focusNode] : [];
    const ql = focusNode !== null ? state.euler.tin[focusNode] : null;
    const qr = focusNode !== null ? state.euler.tout[focusNode] : null;

    root.querySelector('[data-role="invariant"]').textContent =
      "In single-entry DFS order, every node in subtree(u) appears contiguously between tin[u] and tout[u).";

    root.querySelector('[data-role="interval"]').textContent =
      focusNode === null
        ? "Select a node and show its subtree interval."
        : `subtree(${focusNode}) -> [${ql}, ${qr})`;

    root.querySelector('[data-role="nodes"]').textContent =
      focusNode === null ? "-" : subtreeNodes.join(" -> ");

    root.querySelector('[data-role="order"]').textContent = state.euler.order.join(" -> ");

    root.querySelector('[data-role="result"]').textContent =
      focusNode === null
        ? actionText
        : `${actionText} | subtree sum = ${subtreeSum(state, focusNode)} | subtree size = ${qr - ql}`;

    root.querySelector('[data-role="note"]').textContent =
      state.lastUpdatedNode === null
        ? "Blue tree nodes and blue flat cells are the same subtree seen in two coordinate systems."
        : `Node ${state.lastUpdatedNode} changed at flat[${state.euler.tin[state.lastUpdatedNode]}]. Subtree intervals did not move; only one flattened position changed.`;
  }

  function rerender(root, state, actionText) {
    renderTree(root, state);
    renderFlat(root, state);
    renderSummary(root, state, actionText);
  }

  function reset(root, state) {
    state.values = cloneValues();
    state.euler = computeEuler(state.values);
    state.focusNode = 3;
    state.lastUpdatedNode = null;
    rerender(root, state, "Default focus on subtree(3).");
  }

  function showSubtree(root, state) {
    state.focusNode = Number(root.querySelector('[data-role="focus-node"]').value);
    state.lastUpdatedNode = null;
    rerender(root, state, `Focused subtree(${state.focusNode}).`);
  }

  function applyUpdate(root, state) {
    const nodeId = Number(root.querySelector('[data-role="update-node"]').value);
    const newValue = Number(root.querySelector('[data-role="update-value"]').value);
    state.values[nodeId] = newValue;
    state.euler = computeEuler(state.values);
    state.lastUpdatedNode = nodeId;
    rerender(
      root,
      state,
      `Set value(${nodeId}) = ${newValue} at flat[tin[${nodeId}]] = flat[${state.euler.tin[nodeId]}].`,
    );
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const state = {};
    root.querySelector('[data-role="show-subtree"]').addEventListener("click", () => {
      showSubtree(root, state);
    });
    root.querySelector('[data-role="run-update"]').addEventListener("click", () => {
      applyUpdate(root, state);
    });
    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(root, state);
    });

    reset(root, state);
  }

  function boot() {
    document.querySelectorAll("[data-euler-tour-visualizer]").forEach(initOne);
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
