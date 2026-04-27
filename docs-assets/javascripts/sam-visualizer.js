(() => {
  const TEXT = ["a", "b", "a", "a", "b", "b"];

  const NODE_LAYOUT = {
    "0": { x: 340, y: 40 },
    "1": { x: 150, y: 170 },
    "2": { x: 520, y: 170 },
    "3": { x: 600, y: 300 },
    "4": { x: 340, y: 300 },
    "5": { x: 340, y: 440 },
    "6": { x: 520, y: 440 },
    "7": { x: 340, y: 170 },
  };

  const STAGES = [
    {
      label: "Before appending the final 'b'",
      processed: 5,
      visibleNodes: ["0", "1", "2", "3", "4", "5"],
      nodeLabels: {
        "0": "0\nlen=0",
        "1": "1\nlen=1",
        "2": "2\nlen=2",
        "3": "3\nlen=3",
        "4": "4\nlen=4",
        "5": "5\nlen=5\nlast",
      },
      transitions: [
        ["t01a", "0", "1", "a"],
        ["t02b", "0", "2", "b"],
        ["t12b", "1", "2", "b"],
        ["t14a", "1", "4", "a"],
        ["t23a", "2", "3", "a"],
        ["t34a", "3", "4", "a"],
        ["t45b", "4", "5", "b"],
      ],
      suffixLinks: [
        ["l10", "1", "0"],
        ["l20", "2", "0"],
        ["l31", "3", "1"],
        ["l41", "4", "1"],
        ["l52", "5", "2"],
      ],
      activeTransition: "t02b",
      activeSuffixChain: ["l52", "l20"],
      focusNodes: ["5", "2", "0"],
      cloneNode: null,
      invariantText:
        "Every SAM state represents a whole interval of substring lengths, not one substring. The next transition must land in a state whose maximum length fits the current context.",
      stageText:
        "We already processed \"abaab\". To append the final 'b', the extension walks suffix links from last state 5 to state 2 and then to the root.",
      conflictText:
        "At the root, the transition by 'b' already exists and goes to state 2, but len[root] + 1 = 1 while len[2] = 2. That target is too long for the shorter context.",
      repairText:
        "This is the exact clone trigger: an old transition exists, but its target mixes behaviors that should now be split into a shorter class and a longer class.",
      note:
        "If we reused state 2 directly, the root would jump by one character into a state whose maximum represented length is 2, breaking the SAM length invariant.",
    },
    {
      label: "After clone repair",
      processed: 6,
      visibleNodes: ["0", "1", "2", "3", "4", "5", "6", "7"],
      nodeLabels: {
        "0": "0\nlen=0",
        "1": "1\nlen=1",
        "2": "2\nlen=2",
        "3": "3\nlen=3",
        "4": "4\nlen=4",
        "5": "5\nlen=5",
        "6": "6\nlen=6\nnew",
        "7": "7\nlen=1\nclone",
      },
      transitions: [
        ["t01a", "0", "1", "a"],
        ["t07b", "0", "7", "b"],
        ["t12b", "1", "2", "b"],
        ["t14a", "1", "4", "a"],
        ["t23a", "2", "3", "a"],
        ["t26b", "2", "6", "b"],
        ["t34a", "3", "4", "a"],
        ["t45b", "4", "5", "b"],
        ["t52b", "5", "6", "b"],
        ["t73a", "7", "3", "a"],
        ["t76b", "7", "6", "b"],
      ],
      suffixLinks: [
        ["l10", "1", "0"],
        ["l70", "7", "0"],
        ["l27", "2", "7"],
        ["l31", "3", "1"],
        ["l41", "4", "1"],
        ["l52", "5", "2"],
        ["l67", "6", "7"],
      ],
      activeTransition: "t07b",
      activeSuffixChain: ["l27", "l67"],
      focusNodes: ["7", "2", "6"],
      cloneNode: "7",
      invariantText:
        "The clone repairs the boundary between two endpos classes by giving the shorter context its own representative state with a smaller len.",
      stageText:
        "State 7 is the clone. It copies the outgoing transitions of old state 2, but its len is cut down to 1 so the root can transition by 'b' into the correct shorter class.",
      conflictText:
        "Root now goes to clone 7 on 'b', while the old state 2 keeps the longer interval and changes its suffix link to 7. The new real state 6 also links to 7.",
      repairText:
        "This is the whole clone repair: copy outgoing transitions, shorten only the clone's len, redirect the affected transitions, and repoint suffix links.",
      note:
        "After the split, every transition again lands in a state whose length interval matches the context that reached it.",
    },
  ];

  function makeState() {
    return { index: 0 };
  }

  function renderText(root, stage) {
    const host = root.querySelector('[data-role="text-strip"]');
    host.innerHTML = TEXT.map((ch, index) => {
      const classes = ["visual-cell"];
      if (index < stage.processed) {
        classes.push("is-processed");
      }
      if (index === stage.processed && stage.processed < TEXT.length) {
        classes.push("is-current");
      }
      return `
        <div class="${classes.join(" ")}">
          <small>text[${index}]</small>
          <strong>${ch}</strong>
        </div>
      `;
    }).join("");
  }

  function initCy(container) {
    return cytoscape({
      container,
      elements: [],
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
            "text-max-width": 88,
            "text-valign": "center",
            "text-halign": "center",
            "font-size": 12,
            "font-weight": 700,
            color: "#10233f",
            "background-color": "#ffffff",
            "border-width": 2,
            "border-color": "rgba(22, 59, 115, 0.18)",
            width: 78,
            height: 78,
            "line-height": 1.18,
          },
        },
        {
          selector: ".is-transition",
          style: {
            width: 4,
            "curve-style": "bezier",
            "line-color": "rgba(37, 99, 235, 0.46)",
            "target-arrow-shape": "triangle",
            "target-arrow-color": "rgba(37, 99, 235, 0.46)",
            label: "data(label)",
            "font-size": 11,
            "font-weight": 800,
            "text-background-opacity": 1,
            "text-background-color": "rgba(255, 255, 255, 0.9)",
            "text-background-padding": 2,
            "text-rotation": "autorotate",
            color: "#1d4ed8",
          },
        },
        {
          selector: ".is-suffix-link",
          style: {
            width: 3,
            "curve-style": "bezier",
            "line-style": "dashed",
            "line-color": "rgba(107, 114, 128, 0.64)",
            "target-arrow-shape": "triangle",
            "target-arrow-color": "rgba(107, 114, 128, 0.64)",
            label: "link",
            "font-size": 10,
            "font-weight": 700,
            "text-background-opacity": 1,
            "text-background-color": "rgba(255, 255, 255, 0.9)",
            "text-background-padding": 2,
            "text-rotation": "autorotate",
            color: "#6b7280",
          },
        },
        {
          selector: ".is-focus-node",
          style: {
            "background-color": "rgba(191, 219, 254, 0.92)",
            "border-color": "rgba(29, 78, 216, 0.9)",
            "border-width": 4,
          },
        },
        {
          selector: ".is-clone-node",
          style: {
            "background-color": "rgba(233, 213, 255, 0.86)",
            "border-color": "rgba(124, 58, 237, 0.72)",
            "border-width": 4,
          },
        },
        {
          selector: ".is-active-transition",
          style: {
            width: 6,
            "line-color": "rgba(29, 78, 216, 0.96)",
            "target-arrow-color": "rgba(29, 78, 216, 0.96)",
            color: "#1d4ed8",
          },
        },
        {
          selector: ".is-active-link",
          style: {
            width: 5,
            "line-color": "rgba(124, 58, 237, 0.94)",
            "target-arrow-color": "rgba(124, 58, 237, 0.94)",
            color: "#6d28d9",
          },
        },
      ],
    });
  }

  function renderGraph(cy, stage) {
    const elements = [
      ...stage.visibleNodes.map((id) => ({
        data: { id, label: stage.nodeLabels[id] },
        position: NODE_LAYOUT[id],
      })),
      ...stage.transitions.map(([id, source, target, label]) => ({
        data: { id, source, target, label },
        classes: "is-transition",
      })),
      ...stage.suffixLinks.map(([id, source, target]) => ({
        data: { id, source, target, label: "link" },
        classes: "is-suffix-link",
      })),
    ];

    cy.elements().remove();
    cy.add(elements);
    cy.layout({ name: "preset" }).run();

    stage.focusNodes.forEach((id) => cy.$id(id).addClass("is-focus-node"));
    if (stage.cloneNode !== null) {
      cy.$id(stage.cloneNode).addClass("is-clone-node");
    }
    if (stage.activeTransition !== null) {
      cy.$id(stage.activeTransition).addClass("is-active-transition");
    }
    stage.activeSuffixChain.forEach((id) => cy.$id(id).addClass("is-active-link"));
  }

  function renderSummary(root, stage) {
    root.querySelector('[data-role="invariant"]').textContent = stage.invariantText;
    root.querySelector('[data-role="stage"]').textContent = stage.stageText;
    root.querySelector('[data-role="conflict"]').textContent = stage.conflictText;
    root.querySelector('[data-role="repair"]').textContent = stage.repairText;
    root.querySelector('[data-role="note"]').textContent = stage.note;
  }

  function rerender(root, cy, state) {
    const stage = STAGES[state.index];
    renderText(root, stage);
    renderGraph(cy, stage);
    renderSummary(root, stage);
  }

  function advance(state) {
    if (state.index < STAGES.length - 1) {
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
      state.index = STAGES.length - 1;
      rerender(root, cy, state);
    });

    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(state);
      rerender(root, cy, state);
    });

    rerender(root, cy, state);
  }

  function boot() {
    document.querySelectorAll("[data-sam-visualizer]").forEach(initOne);
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
