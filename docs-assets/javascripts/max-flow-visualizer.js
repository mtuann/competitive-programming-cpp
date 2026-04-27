(() => {
  const NODES = [
    { id: "s", label: "s", x: 60, y: 190 },
    { id: "a", label: "a", x: 240, y: 90 },
    { id: "b", label: "b", x: 240, y: 300 },
    { id: "c", label: "c", x: 430, y: 190 },
    { id: "t", label: "t", x: 620, y: 190 },
  ];

  const ORIGINAL_EDGES = [
    { id: "sa", source: "s", target: "a", capacity: 1 },
    { id: "sb", source: "s", target: "b", capacity: 1 },
    { id: "ac", source: "a", target: "c", capacity: 1 },
    { id: "bc", source: "b", target: "c", capacity: 1 },
    { id: "ct", source: "c", target: "t", capacity: 1 },
    { id: "at", source: "a", target: "t", capacity: 1 },
  ];

  const RESIDUAL_EDGE_DEFS = ORIGINAL_EDGES.flatMap((edge) => [
    { id: `f-${edge.id}`, source: edge.source, target: edge.target, base: edge.id, direction: "forward" },
    { id: `r-${edge.id}`, source: edge.target, target: edge.source, base: edge.id, direction: "reverse" },
  ]);

  const STATES = [
    {
      flowValue: 0,
      flows: { sa: 0, sb: 0, ac: 0, bc: 0, ct: 0, at: 0 },
      activeResidualPath: ["f-sa", "f-ac", "f-ct"],
      bottleneck: 1,
      reachable: ["s", "a", "b", "c", "t"],
      cutEdges: [],
      pathText: "Residual path: s -> a -> c -> t",
      reverseText: "No reverse residual edge is needed yet; the first augmentation is a pure forward push.",
      note: "Apply this path and the edge c -> t becomes saturated, which sets up the need for rerouting on the next residual search.",
      stageLabel: "Ready to apply the first augmenting path.",
    },
    {
      flowValue: 1,
      flows: { sa: 1, sb: 0, ac: 1, bc: 0, ct: 1, at: 0 },
      activeResidualPath: ["f-sb", "f-bc", "r-ac", "f-at"],
      bottleneck: 1,
      reachable: ["s", "a", "b", "c", "t"],
      cutEdges: [],
      pathText: "Residual path: s -> b -> c -> a -> t",
      reverseText:
        "The residual edge c -> a is the reverse of original edge a -> c. Using it cancels that earlier unit of flow and reroutes it toward a -> t instead.",
      note: "This is the whole reason reverse edges exist: the second augmenting path repairs a previous routing choice instead of being trapped by it.",
      stageLabel: "One unit is already flowing. The next augmenting path must use a reverse edge.",
    },
    {
      flowValue: 2,
      flows: { sa: 1, sb: 1, ac: 0, bc: 1, ct: 1, at: 1 },
      activeResidualPath: [],
      bottleneck: 0,
      reachable: ["s"],
      cutEdges: ["sa", "sb"],
      pathText: "No s -> t residual path remains.",
      reverseText:
        "At this point every route out of s is saturated, so no residual repair can increase the throughput any further.",
      note: "Reachable set A = {s}. The original edges from A to V \\ A are s -> a and s -> b, both saturated, so their total capacity 2 certifies the max flow.",
      stageLabel: "Maximum flow reached; read the min-cut witness from residual reachability.",
    },
  ];

  function residualCapacity(base, direction, flows) {
    const cap = ORIGINAL_EDGES.find((edge) => edge.id === base).capacity;
    const flow = flows[base];
    return direction === "forward" ? cap - flow : flow;
  }

  function makeState() {
    return { index: 0 };
  }

  function initCy(container) {
    return cytoscape({
      container,
      elements: [
        ...NODES.map((node) => ({
          data: { id: node.id, label: node.label },
          position: { x: node.x, y: node.y },
        })),
        ...ORIGINAL_EDGES.map((edge) => ({
          data: {
            id: edge.id,
            source: edge.source,
            target: edge.target,
            label: `0/${edge.capacity}`,
          },
          classes: "is-flow-edge",
        })),
        ...RESIDUAL_EDGE_DEFS.map((edge) => ({
          data: {
            id: edge.id,
            source: edge.source,
            target: edge.target,
            label: "",
          },
          classes: edge.direction === "forward" ? "is-residual-forward" : "is-residual-reverse",
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
            "text-valign": "center",
            "text-halign": "center",
            "font-size": 16,
            "font-weight": 800,
            color: "#10233f",
            "background-color": "#ffffff",
            "border-width": 3,
            "border-color": "rgba(22, 59, 115, 0.18)",
            width: 58,
            height: 58,
          },
        },
        {
          selector: ".is-flow-edge",
          style: {
            width: 4,
            "curve-style": "bezier",
            "line-color": "rgba(22, 59, 115, 0.62)",
            "target-arrow-shape": "triangle",
            "target-arrow-color": "rgba(22, 59, 115, 0.62)",
            label: "data(label)",
            "font-size": 12,
            "font-weight": 800,
            "text-background-opacity": 1,
            "text-background-color": "rgba(255, 255, 255, 0.92)",
            "text-background-padding": 2,
            "text-rotation": "autorotate",
            color: "#10233f",
          },
        },
        {
          selector: ".is-residual-forward, .is-residual-reverse",
          style: {
            width: 3,
            "curve-style": "bezier",
            "line-style": "dashed",
            label: "data(label)",
            "font-size": 10,
            "font-weight": 700,
            "text-background-opacity": 1,
            "text-background-color": "rgba(255, 255, 255, 0.9)",
            "text-background-padding": 2,
            "text-rotation": "autorotate",
            "target-arrow-shape": "triangle",
            opacity: 0.92,
          },
        },
        {
          selector: ".is-residual-forward",
          style: {
            "line-color": "rgba(37, 99, 235, 0.38)",
            "target-arrow-color": "rgba(37, 99, 235, 0.38)",
            color: "#1d4ed8",
          },
        },
        {
          selector: ".is-residual-reverse",
          style: {
            "line-color": "rgba(107, 114, 128, 0.54)",
            "target-arrow-color": "rgba(107, 114, 128, 0.54)",
            color: "#6b7280",
          },
        },
        {
          selector: ".is-hidden-residual",
          style: {
            display: "none",
          },
        },
        {
          selector: ".is-active-path",
          style: {
            width: 6,
            "line-color": "rgba(5, 150, 105, 0.96)",
            "target-arrow-color": "rgba(5, 150, 105, 0.96)",
            color: "#047857",
          },
        },
        {
          selector: ".is-active-reverse",
          style: {
            width: 6,
            "line-color": "rgba(124, 58, 237, 0.96)",
            "target-arrow-color": "rgba(124, 58, 237, 0.96)",
            color: "#6d28d9",
          },
        },
        {
          selector: ".is-cut-edge",
          style: {
            width: 7,
            "line-color": "rgba(220, 38, 38, 0.9)",
            "target-arrow-color": "rgba(220, 38, 38, 0.9)",
            color: "#b91c1c",
          },
        },
        {
          selector: ".is-reachable",
          style: {
            "background-color": "rgba(191, 219, 254, 0.92)",
            "border-color": "rgba(29, 78, 216, 0.86)",
          },
        },
        {
          selector: ".is-unreachable",
          style: {
            "background-color": "rgba(243, 244, 246, 0.82)",
            "border-color": "rgba(148, 163, 184, 0.28)",
          },
        },
      ],
    });
  }

  function clearClasses(cy) {
    cy.elements().removeClass(
      "is-hidden-residual is-active-path is-active-reverse is-cut-edge is-reachable is-unreachable",
    );
  }

  function renderSummary(root, stage) {
    root.querySelector('[data-role="invariant"]').textContent =
      "Residual edges are the real working object: forward residual means 'can still send more', backward residual means 'can cancel and reroute flow already sent'.";
    root.querySelector('[data-role="stage"]').textContent = stage.stageLabel;
    root.querySelector('[data-role="value"]').textContent = `|f| = ${stage.flowValue}`;
    root.querySelector('[data-role="path"]').textContent =
      stage.activeResidualPath.length === 0
        ? stage.pathText
        : `${stage.pathText} | bottleneck = ${stage.bottleneck}`;
    root.querySelector('[data-role="reverse"]').textContent = stage.reverseText;
    root.querySelector('[data-role="cut"]').textContent =
      stage.cutEdges.length === 0
        ? "No cut witness yet; an s -> t residual path still exists."
        : `Reachable set A = {${stage.reachable.join(", ")}} | cut edges = ${stage.cutEdges.join(", ")} | cut capacity = ${stage.cutEdges.length}`;
    root.querySelector('[data-role="note"]').textContent = stage.note;
  }

  function rerender(root, cy, state) {
    const stage = STATES[state.index];
    clearClasses(cy);

    ORIGINAL_EDGES.forEach((edge) => {
      const cyEdge = cy.$id(edge.id);
      cyEdge.data("label", `${stage.flows[edge.id]}/${edge.capacity}`);
    });

    RESIDUAL_EDGE_DEFS.forEach((edge) => {
      const cyEdge = cy.$id(edge.id);
      const res = residualCapacity(edge.base, edge.direction, stage.flows);
      if (res > 0) {
        cyEdge.data("label", `r=${res}`);
      } else {
        cyEdge.data("label", "");
        cyEdge.addClass("is-hidden-residual");
      }
    });

    stage.activeResidualPath.forEach((edgeId) => {
      const cyEdge = cy.$id(edgeId);
      cyEdge.removeClass("is-hidden-residual");
      if (edgeId.startsWith("r-")) {
        cyEdge.addClass("is-active-reverse");
      } else {
        cyEdge.addClass("is-active-path");
      }
    });

    cy.nodes().forEach((node) => {
      if (stage.reachable.includes(node.id())) {
        node.addClass("is-reachable");
      } else {
        node.addClass("is-unreachable");
      }
    });

    stage.cutEdges.forEach((edgeId) => {
      cy.$id(edgeId).addClass("is-cut-edge");
    });

    renderSummary(root, stage);
  }

  function advance(state) {
    if (state.index < STATES.length - 1) {
      state.index += 1;
    }
  }

  function reset(state) {
    state.index = 0;
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const cy = initCy(root.querySelector('[data-role="canvas"]'));
    const state = makeState();

    root.querySelector('[data-role="step"]').addEventListener("click", () => {
      advance(state);
      rerender(root, cy, state);
    });

    root.querySelector('[data-role="run"]').addEventListener("click", () => {
      state.index = STATES.length - 1;
      rerender(root, cy, state);
    });

    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(state);
      rerender(root, cy, state);
    });

    rerender(root, cy, state);
  }

  function boot() {
    document.querySelectorAll("[data-max-flow-visualizer]").forEach(initOne);
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
