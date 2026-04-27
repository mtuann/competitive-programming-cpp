(() => {
  const TEXT = ["u", "s", "h", "e", "r", "s"];

  const NODES = [
    { id: "0", prefix: "(root)", label: "0\nroot", output: [], x: 340, y: 34 },
    { id: "1", prefix: "h", label: "1\nh", output: [], x: 210, y: 146 },
    { id: "2", prefix: "he", label: "2\nhe\nout: he", output: ["he"], x: 120, y: 264 },
    { id: "3", prefix: "her", label: "3\nher", output: [], x: 120, y: 392 },
    { id: "4", prefix: "hers", label: "4\nhers\nout: hers", output: ["hers"], x: 120, y: 514 },
    { id: "5", prefix: "s", label: "5\ns", output: [], x: 470, y: 146 },
    { id: "6", prefix: "sh", label: "6\nsh", output: [], x: 560, y: 264 },
    { id: "7", prefix: "she", label: "7\nshe\nout: she, he", output: ["she", "he"], x: 560, y: 392 },
    { id: "8", prefix: "hi", label: "8\nhi", output: [], x: 300, y: 264 },
    { id: "9", prefix: "his", label: "9\nhis\nout: his", output: ["his"], x: 300, y: 392 },
  ];

  const GOTO_EDGES = [
    { id: "g01", source: "0", target: "1", label: "h" },
    { id: "g12", source: "1", target: "2", label: "e" },
    { id: "g23", source: "2", target: "3", label: "r" },
    { id: "g34", source: "3", target: "4", label: "s" },
    { id: "g05", source: "0", target: "5", label: "s" },
    { id: "g56", source: "5", target: "6", label: "h" },
    { id: "g67", source: "6", target: "7", label: "e" },
    { id: "g18", source: "1", target: "8", label: "i" },
    { id: "g89", source: "8", target: "9", label: "s" },
  ];

  const FAIL_EDGES = [
    { id: "f10", source: "1", target: "0" },
    { id: "f20", source: "2", target: "0" },
    { id: "f30", source: "3", target: "0" },
    { id: "f45", source: "4", target: "5" },
    { id: "f50", source: "5", target: "0" },
    { id: "f61", source: "6", target: "1" },
    { id: "f72", source: "7", target: "2" },
    { id: "f80", source: "8", target: "0" },
    { id: "f95", source: "9", target: "5" },
  ];

  const GOTO = {
    "0": { h: "1", s: "5" },
    "1": { e: "2", i: "8" },
    "2": { r: "3" },
    "3": { s: "4" },
    "4": {},
    "5": { h: "6" },
    "6": { e: "7" },
    "7": {},
    "8": { s: "9" },
    "9": {},
  };

  const FAIL = {
    "0": "0",
    "1": "0",
    "2": "0",
    "3": "0",
    "4": "5",
    "5": "0",
    "6": "1",
    "7": "2",
    "8": "0",
    "9": "5",
  };

  const OUTPUT = Object.fromEntries(NODES.map((node) => [node.id, node.output]));
  const PREFIX = Object.fromEntries(NODES.map((node) => [node.id, node.prefix]));

  function makeState() {
    return {
      index: 0,
      currentState: "0",
      done: false,
      activeGoto: null,
      activeFails: [],
      matched: [],
      actionText: "Ready to scan the text against the pattern dictionary {he, she, hers, his}.",
      lastProcessedIndex: null,
    };
  }

  function initCy(container) {
    return cytoscape({
      container,
      elements: [
        ...NODES.map((node) => ({
          data: {
            id: node.id,
            label: node.label,
            outputCount: node.output.length,
          },
          position: { x: node.x, y: node.y },
        })),
        ...GOTO_EDGES.map((edge) => ({
          data: { id: edge.id, source: edge.source, target: edge.target, label: edge.label },
          classes: "is-goto-edge",
        })),
        ...FAIL_EDGES.map((edge) => ({
          data: { id: edge.id, source: edge.source, target: edge.target, label: "fail" },
          classes: "is-fail-edge",
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
            "text-max-width": 86,
            "text-valign": "center",
            "text-halign": "center",
            "font-size": 11,
            "font-weight": 700,
            color: "#10233f",
            "background-color": "#ffffff",
            "border-width": 2,
            "border-color": "rgba(22, 59, 115, 0.20)",
            width: 78,
            height: 78,
            "line-height": 1.15,
          },
        },
        {
          selector: "edge",
          style: {
            width: 3,
            "curve-style": "bezier",
            "target-arrow-shape": "triangle",
            "target-arrow-color": "rgba(22, 59, 115, 0.5)",
            "arrow-scale": 0.9,
            label: "data(label)",
            "font-size": 10,
            "text-background-opacity": 1,
            "text-background-color": "rgba(255, 255, 255, 0.86)",
            "text-background-padding": 2,
            "text-rotation": "autorotate",
            color: "#10233f",
          },
        },
        {
          selector: ".is-goto-edge",
          style: {
            "line-color": "rgba(37, 99, 235, 0.46)",
          },
        },
        {
          selector: ".is-fail-edge",
          style: {
            "line-color": "rgba(107, 114, 128, 0.72)",
            "line-style": "dashed",
            "target-arrow-color": "rgba(107, 114, 128, 0.72)",
          },
        },
        {
          selector: ".is-current-state",
          style: {
            "background-color": "rgba(191, 219, 254, 0.92)",
            "border-color": "rgba(29, 78, 216, 0.9)",
            "border-width": 4,
          },
        },
        {
          selector: ".has-output",
          style: {
            "background-color": "rgba(253, 230, 138, 0.72)",
            "border-color": "rgba(217, 119, 6, 0.42)",
          },
        },
        {
          selector: ".is-fail-visited",
          style: {
            "background-color": "rgba(233, 213, 255, 0.82)",
            "border-color": "rgba(124, 58, 237, 0.52)",
          },
        },
        {
          selector: ".is-active-goto",
          style: {
            width: 6,
            "line-color": "rgba(29, 78, 216, 0.94)",
            "target-arrow-color": "rgba(29, 78, 216, 0.94)",
          },
        },
        {
          selector: ".is-active-fail",
          style: {
            width: 5,
            "line-color": "rgba(124, 58, 237, 0.94)",
            "target-arrow-color": "rgba(124, 58, 237, 0.94)",
          },
        },
        {
          selector: ".is-muted",
          style: {
            opacity: 0.22,
          },
        },
      ],
    });
  }

  function clearClasses(cy) {
    cy.elements().removeClass(
      "is-current-state has-output is-fail-visited is-active-goto is-active-fail is-muted",
    );
  }

  function renderText(root, state) {
    const host = root.querySelector('[data-role="text-strip"]');
    host.innerHTML = TEXT.map((ch, index) => {
      const classes = ["visual-cell"];
      if (index < state.index) {
        classes.push("is-processed");
      } else if (index === state.index && !state.done) {
        classes.push("is-current");
      }
      if (state.lastProcessedIndex === index) {
        classes.push("is-highlight");
      }
      return `
        <div class="${classes.join(" ")}">
          <small>text[${index}]</small>
          <strong>${ch}</strong>
        </div>
      `;
    }).join("");
  }

  function renderSummary(root, state) {
    const processed = TEXT.slice(0, state.index).join("");
    const nextChar = state.done ? "done" : `'${TEXT[state.index]}'`;

    root.querySelector('[data-role="state-meaning"]').textContent =
      `Current state ${state.currentState} means the longest suffix of the processed text that is also a trie prefix is "${PREFIX[state.currentState]}".`;

    root.querySelector('[data-role="prefix"]').textContent =
      `processed = "${processed}" | next char = ${nextChar}`;

    root.querySelector('[data-role="transition"]').textContent = state.actionText;

    root.querySelector('[data-role="failure"]').textContent =
      state.activeFails.length === 0
        ? "No failure jump was needed on the latest step."
        : `Failure chain used: ${state.activeFails.map((edgeId) => edgeId.slice(1)).join(" -> ")}`;

    root.querySelector('[data-role="output"]').textContent =
      state.matched.length === 0
        ? "No pattern ended on the latest step."
        : `Matched on latest step: ${state.matched.join(", ")}`;

    root.querySelector('[data-role="note"]').textContent =
      "Failure links preserve useful suffix state, so the scan reuses previous work instead of restarting from the root after every mismatch.";
  }

  function rerender(root, cy, state) {
    clearClasses(cy);
    renderText(root, state);

    cy.nodes().forEach((node) => node.addClass("is-muted"));
    cy.edges().forEach((edge) => edge.addClass("is-muted"));

    cy.$id("0").removeClass("is-muted");
    cy.$id(state.currentState).removeClass("is-muted").addClass("is-current-state");

    NODES.forEach((node) => {
      if (node.output.length > 0) {
        cy.$id(node.id).addClass("has-output");
      }
    });

    if (state.activeGoto) {
      cy.$id(state.activeGoto).removeClass("is-muted").addClass("is-active-goto");
      const edge = GOTO_EDGES.find((item) => item.id === state.activeGoto);
      if (edge) {
        cy.$id(edge.source).removeClass("is-muted");
        cy.$id(edge.target).removeClass("is-muted");
      }
    }

    state.activeFails.forEach((edgeId) => {
      cy.$id(edgeId).removeClass("is-muted").addClass("is-active-fail");
      const edge = FAIL_EDGES.find((item) => item.id === edgeId);
      if (edge) {
        cy.$id(edge.source).removeClass("is-muted").addClass("is-fail-visited");
        cy.$id(edge.target).removeClass("is-muted").addClass("is-fail-visited");
      }
    });

    renderSummary(root, state);
  }

  function step(state) {
    state.activeGoto = null;
    state.activeFails = [];
    state.matched = [];
    state.lastProcessedIndex = null;

    if (state.done) {
      state.actionText = "Text scan already finished. Reset to replay the automaton walk.";
      return;
    }

    const ch = TEXT[state.index];
    let at = state.currentState;
    const failEdges = [];

    while (at !== "0" && !GOTO[at][ch]) {
      const next = FAIL[at];
      failEdges.push(`f${at}${next}`);
      at = next;
    }

    state.activeFails = failEdges;
    state.lastProcessedIndex = state.index;

    if (GOTO[at][ch]) {
      const next = GOTO[at][ch];
      const gotoEdge = GOTO_EDGES.find((edge) => edge.source === at && edge.target === next && edge.label === ch);
      state.activeGoto = gotoEdge ? gotoEdge.id : null;
      state.currentState = next;
      state.matched = OUTPUT[next];

      if (failEdges.length === 0) {
        state.actionText = `Read '${ch}' and followed one trie edge directly into state ${next}.`;
      } else {
        state.actionText = `Read '${ch}', failed from the old state along failure links, then resumed from state ${at} and followed goto('${ch}') into state ${next}.`;
      }
    } else {
      state.currentState = "0";
      state.actionText =
        failEdges.length === 0
          ? `Read '${ch}' at the root and found no trie edge, so the automaton stays at the root.`
          : `Read '${ch}', climbed failure links to the root, and still found no outgoing trie edge, so the automaton stays at the root.`;
    }

    state.index += 1;
    if (state.index >= TEXT.length) {
      state.done = true;
    }
  }

  function reset(root, cy, state) {
    Object.assign(state, makeState());
    rerender(root, cy, state);
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const cy = initCy(root.querySelector('[data-role="canvas"]'));
    const state = makeState();

    root.querySelector('[data-role="step"]').addEventListener("click", () => {
      step(state);
      rerender(root, cy, state);
    });

    root.querySelector('[data-role="run"]').addEventListener("click", () => {
      let guard = 0;
      while (!state.done && guard < 32) {
        step(state);
        guard += 1;
      }
      rerender(root, cy, state);
    });

    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(root, cy, state);
    });

    rerender(root, cy, state);
  }

  function boot() {
    document.querySelectorAll("[data-aho-visualizer]").forEach(initOne);
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
