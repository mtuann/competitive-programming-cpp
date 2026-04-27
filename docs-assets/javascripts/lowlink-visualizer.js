(() => {
  const NODES = [
    { id: "1", label: "1\ntin=0\nlow=0", tin: 0, low: 0, x: 320, y: 40, parent: null },
    { id: "2", label: "2\ntin=1\nlow=0", tin: 1, low: 0, x: 180, y: 150, parent: "1" },
    { id: "3", label: "3\ntin=2\nlow=0", tin: 2, low: 0, x: 460, y: 150, parent: "2" },
    { id: "4", label: "4\ntin=3\nlow=3", tin: 3, low: 3, x: 180, y: 300, parent: "2" },
    { id: "5", label: "5\ntin=4\nlow=3", tin: 4, low: 3, x: 60, y: 430, parent: "4" },
    { id: "6", label: "6\ntin=5\nlow=3", tin: 5, low: 3, x: 300, y: 430, parent: "5" },
    { id: "7", label: "7\ntin=6\nlow=6", tin: 6, low: 6, x: 360, y: 300, parent: "4" },
  ];

  const EDGES = [
    { id: "1-2", source: "1", target: "2", kind: "tree" },
    { id: "2-3", source: "2", target: "3", kind: "tree" },
    { id: "2-4", source: "2", target: "4", kind: "tree" },
    { id: "4-5", source: "4", target: "5", kind: "tree" },
    { id: "5-6", source: "5", target: "6", kind: "tree" },
    { id: "4-7", source: "4", target: "7", kind: "tree" },
    { id: "3-1", source: "3", target: "1", kind: "back" },
    { id: "6-4", source: "6", target: "4", kind: "back" },
  ];

  const CHILD_INFO = {
    "2": {
      parent: "1",
      subtree: ["2", "3", "4", "5", "6", "7"],
      witnessEdges: ["3-1"],
      bridge: false,
      articulation: false,
      articulationText:
        "Parent 1 is the DFS root. Even though low[2] = tin[1], root 1 is not a cut vertex here because it has only one DFS child.",
      note:
        "The back edge 3-1 lets the whole subtree of 2 reconnect to the root, so edge 1-2 is not a bridge.",
    },
    "3": {
      parent: "2",
      subtree: ["3"],
      witnessEdges: ["3-1"],
      bridge: false,
      articulation: false,
      articulationText: "low[3] = 0 < tin[2] = 1, so removing 2 would not trap node 3 away from higher ancestors.",
      note:
        "The back edge 3-1 is exactly the witness that saves tree edge 2-3 from being a bridge.",
    },
    "4": {
      parent: "2",
      subtree: ["4", "5", "6", "7"],
      witnessEdges: [],
      bridge: true,
      articulation: true,
      articulationText: "low[4] = 3 >= tin[2] = 1, so vertex 2 separates the subtree rooted at 4 from the rest of the graph.",
      note:
        "There is no back edge from subtree(4) to vertex 2 or any ancestor of 2, so edge 2-4 is a bridge.",
    },
    "5": {
      parent: "4",
      subtree: ["5", "6"],
      witnessEdges: ["6-4"],
      bridge: false,
      articulation: true,
      articulationText: "low[5] = tin[4] = 3, so 4 is still an articulation point: the subtree can reconnect only through 4 itself, not above 4.",
      note:
        "The back edge 6-4 keeps edge 4-5 inside one cycle, so 4-5 is not a bridge even though 4 remains a cut vertex.",
    },
    "6": {
      parent: "5",
      subtree: ["6"],
      witnessEdges: ["6-4"],
      bridge: false,
      articulation: false,
      articulationText: "low[6] = 3 < tin[5] = 4, so deleting 5 would not isolate 6 from higher ancestors.",
      note:
        "Back edge 6-4 jumps above parent 5, which is why tree edge 5-6 is not a bridge and vertex 5 is not a cut vertex.",
    },
    "7": {
      parent: "4",
      subtree: ["7"],
      witnessEdges: [],
      bridge: true,
      articulation: true,
      articulationText: "low[7] = 6 >= tin[4] = 3, so vertex 4 separates leaf 7 from the rest of the component.",
      note:
        "Subtree(7) has no back edge at all, so edge 4-7 is a pure bridge and 4 is a cut vertex for that child.",
    },
  };

  function ancestorsOf(nodeId) {
    const ancestors = [];
    let cur = CHILD_INFO[nodeId].parent;
    while (cur !== null) {
      ancestors.push(cur);
      const parent = NODES.find((node) => node.id === cur).parent;
      cur = parent;
    }
    return ancestors;
  }

  function relevantEdgeIds(childId, relevantNodes) {
    const witness = new Set(CHILD_INFO[childId].witnessEdges);
    return EDGES.filter((edge) => {
      if (witness.has(edge.id)) {
        return true;
      }
      return relevantNodes.has(edge.source) && relevantNodes.has(edge.target);
    }).map((edge) => edge.id);
  }

  function initCy(container) {
    return cytoscape({
      container,
      elements: [
        ...NODES.map((node) => ({
          data: { id: node.id, label: node.label, tin: node.tin, low: node.low },
          position: { x: node.x, y: node.y },
        })),
        ...EDGES.map((edge) => ({
          data: { id: edge.id, source: edge.source, target: edge.target, kind: edge.kind },
          classes: edge.kind === "tree" ? "is-tree-edge" : "is-back-edge",
        })),
      ],
      layout: { name: "preset" },
      userZoomingEnabled: false,
      userPanningEnabled: false,
      autoungrabify: true,
      boxSelectionEnabled: false,
      style: [
        {
          selector: "node",
          style: {
            label: "data(label)",
            "text-wrap": "wrap",
            "text-max-width": 76,
            "text-valign": "center",
            "text-halign": "center",
            "font-size": 11,
            "font-weight": 700,
            color: "#10233f",
            "background-color": "#ffffff",
            "border-width": 2,
            "border-color": "rgba(22, 59, 115, 0.20)",
            width: 72,
            height: 72,
            "line-height": 1.18,
          },
        },
        {
          selector: "edge",
          style: {
            width: 3,
            "curve-style": "bezier",
            opacity: 0.95,
          },
        },
        {
          selector: ".is-tree-edge",
          style: {
            "line-color": "rgba(37, 99, 235, 0.42)",
            "target-arrow-shape": "none",
          },
        },
        {
          selector: ".is-back-edge",
          style: {
            "line-color": "rgba(107, 114, 128, 0.68)",
            "line-style": "dashed",
          },
        },
        {
          selector: ".is-subtree",
          style: {
            "background-color": "rgba(191, 219, 254, 0.92)",
            "border-color": "rgba(37, 99, 235, 0.58)",
          },
        },
        {
          selector: ".is-ancestor",
          style: {
            "background-color": "rgba(253, 230, 138, 0.86)",
            "border-color": "rgba(217, 119, 6, 0.4)",
          },
        },
        {
          selector: ".is-focus-parent",
          style: {
            "border-width": 4,
            "border-color": "rgba(217, 119, 6, 0.88)",
          },
        },
        {
          selector: ".is-focus-child",
          style: {
            "border-width": 4,
            "border-color": "rgba(29, 78, 216, 0.92)",
          },
        },
        {
          selector: ".is-focus-edge",
          style: {
            width: 6,
            "line-color": "rgba(220, 38, 38, 0.82)",
          },
        },
        {
          selector: ".is-safe-edge",
          style: {
            "line-color": "rgba(5, 150, 105, 0.72)",
          },
        },
        {
          selector: ".is-witness",
          style: {
            width: 5,
            "line-color": "rgba(5, 150, 105, 0.92)",
          },
        },
        {
          selector: ".is-muted",
          style: {
            opacity: 0.2,
          },
        },
      ],
    });
  }

  function clearClasses(cy) {
    cy.elements().removeClass(
      "is-subtree is-ancestor is-focus-parent is-focus-child is-focus-edge is-safe-edge is-witness is-muted",
    );
  }

  function renderSummary(root, childId) {
    const info = CHILD_INFO[childId];
    const parentNode = NODES.find((node) => node.id === info.parent);
    const childNode = NODES.find((node) => node.id === childId);

    root.querySelector('[data-role="invariant"]').textContent =
      "low[child] is the smallest tin reachable from that child subtree by any number of tree edges down plus at most one back edge up.";

    root.querySelector('[data-role="focus"]').textContent =
      `Inspect tree edge (${info.parent}, ${childId}) with tin[parent] = ${parentNode.tin} and low[child] = ${childNode.low}.`;

    root.querySelector('[data-role="subtree"]').textContent =
      `subtree(${childId}) = ${info.subtree.join(" -> ")}`;

    root.querySelector('[data-role="witness"]').textContent =
      info.witnessEdges.length === 0
        ? "No witness back edge exists from this subtree to the parent or any ancestor."
        : `Witness back edge(s): ${info.witnessEdges.join(", ")}`;

    root.querySelector('[data-role="bridge"]').textContent =
      `${childNode.low} > ${parentNode.tin} -> ${info.bridge ? "yes" : "no"}; edge (${info.parent}, ${childId}) ${info.bridge ? "is" : "is not"} a bridge.`;

    root.querySelector('[data-role="articulation"]').textContent = info.articulationText;
    root.querySelector('[data-role="note"]').textContent = info.note;
  }

  function rerender(root, cy, childId) {
    clearClasses(cy);

    const info = CHILD_INFO[childId];
    const subtree = new Set(info.subtree);
    const ancestors = new Set(ancestorsOf(childId));
    const relevantNodes = new Set([...subtree, ...ancestors]);
    const relevantEdges = new Set(relevantEdgeIds(childId, relevantNodes));

    cy.nodes().forEach((node) => {
      if (!relevantNodes.has(node.id())) {
        node.addClass("is-muted");
        return;
      }
      if (subtree.has(node.id())) {
        node.addClass("is-subtree");
      }
      if (ancestors.has(node.id())) {
        node.addClass("is-ancestor");
      }
    });

    cy.$id(info.parent).addClass("is-focus-parent");
    cy.$id(childId).addClass("is-focus-child");

    cy.edges().forEach((edge) => {
      if (!relevantEdges.has(edge.id())) {
        edge.addClass("is-muted");
      }
    });

    const focusEdge = cy.$id(`${info.parent}-${childId}`);
    focusEdge.addClass("is-focus-edge");
    if (!info.bridge) {
      focusEdge.addClass("is-safe-edge");
    }

    info.witnessEdges.forEach((edgeId) => {
      cy.$id(edgeId).addClass("is-witness");
    });

    renderSummary(root, childId);
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const container = root.querySelector('[data-role="canvas"]');
    const cy = initCy(container);
    const select = root.querySelector('[data-role="child"]');

    const apply = () => {
      rerender(root, cy, select.value);
    };

    root.querySelector('[data-role="inspect"]').addEventListener("click", apply);
    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      select.value = "4";
      apply();
    });
    select.addEventListener("change", apply);

    apply();
  }

  function boot() {
    document.querySelectorAll("[data-lowlink-visualizer]").forEach(initOne);
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
