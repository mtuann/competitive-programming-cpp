(() => {
  const GRAPH = {
    nodes: [
      { id: "A", x: 120, y: 40 },
      { id: "B", x: 40, y: 130 },
      { id: "C", x: 200, y: 130 },
      { id: "D", x: 20, y: 230 },
      { id: "E", x: 110, y: 230 },
      { id: "F", x: 225, y: 230 },
      { id: "G", x: 95, y: 330 },
      { id: "H", x: 245, y: 330 },
    ],
    edges: [
      ["A", "B"],
      ["A", "C"],
      ["B", "D"],
      ["B", "E"],
      ["C", "E"],
      ["C", "F"],
      ["E", "G"],
      ["F", "H"],
    ],
  };

  function buildAdjacency() {
    const adj = new Map();
    for (const node of GRAPH.nodes) {
      adj.set(node.id, []);
    }
    for (const [u, v] of GRAPH.edges) {
      adj.get(u).push(v);
      adj.get(v).push(u);
    }
    for (const list of adj.values()) {
      list.sort();
    }
    return adj;
  }

  function bfs(source, adj) {
    const visited = new Set([source]);
    const dist = { [source]: 0 };
    const parent = { [source]: "-" };
    const order = [];
    const steps = [];
    const queue = [source];

    while (queue.length) {
      const u = queue.shift();
      order.push(u);
      for (const v of adj.get(u)) {
        if (visited.has(v)) {
          continue;
        }
        visited.add(v);
        parent[v] = u;
        dist[v] = dist[u] + 1;
        queue.push(v);
      }
      steps.push({
        node: u,
        frontier: [...queue],
        invariant:
          "BFS fixes shortest unweighted distance when a node is first pushed into the queue.",
        note: `Process ${u}; every newly discovered neighbor becomes part of the next distance layer.`,
      });
    }

    return {
      order,
      parent,
      metric: dist,
      frontierLabel: "Queue",
      metricLabel: "Distance",
      steps,
    };
  }

  function dfs(source, adj) {
    const visited = new Set();
    const parent = { [source]: "-" };
    const depth = { [source]: 0 };
    const order = [];
    const steps = [];
    const stack = [];

    function visit(u) {
      visited.add(u);
      stack.push(u);
      order.push(u);
      steps.push({
        node: u,
        frontier: [...stack],
        invariant:
          "DFS keeps one active search branch visible through the recursion stack.",
        note: `Enter ${u}; DFS now commits to this branch until it can no longer go deeper.`,
      });
      for (const v of adj.get(u)) {
        if (visited.has(v)) {
          continue;
        }
        parent[v] = u;
        depth[v] = depth[u] + 1;
        visit(v);
      }
      stack.pop();
    }

    visit(source);
    return {
      order,
      parent,
      metric: depth,
      frontierLabel: "Active branch",
      metricLabel: "Depth",
      steps,
    };
  }

  function formatMap(keys, map) {
    return keys.map((key) => `${key}:${map[key]}`).join("  ");
  }

  function loadCytoscape() {
    if (window.cytoscape) {
      return Promise.resolve(window.cytoscape);
    }
    if (window.__cpCytoscapePromise) {
      return window.__cpCytoscapePromise;
    }
    window.__cpCytoscapePromise = new Promise((resolve, reject) => {
      const script = document.createElement("script");
      script.src = "https://cdn.jsdelivr.net/npm/cytoscape@3.33.2/dist/cytoscape.min.js";
      script.async = true;
      script.onload = () => resolve(window.cytoscape);
      script.onerror = () => reject(new Error("Cytoscape.js failed to load."));
      document.head.appendChild(script);
    });
    return window.__cpCytoscapePromise;
  }

  function createGraph(container) {
    const elements = [
      ...GRAPH.nodes.map((node) => ({
        data: { id: node.id, label: node.id },
        position: { x: node.x, y: node.y },
      })),
      ...GRAPH.edges.map(([u, v]) => ({
        data: { id: `${u}-${v}`, source: u, target: v },
      })),
    ];

    return window.cytoscape({
      container,
      elements,
      layout: { name: "preset", padding: 18 },
      autoungrabify: true,
      autounselectify: true,
      boxSelectionEnabled: false,
      wheelSensitivity: 0.2,
      style: [
        {
          selector: "node",
          style: {
            "background-color": "#90b7ff",
            color: "#163b73",
            label: "data(label)",
            "text-valign": "center",
            "text-halign": "center",
            "font-weight": 800,
            "font-size": 16,
            width: 44,
            height: 44,
            "border-width": 2,
            "border-color": "#3b6db8",
          },
        },
        {
          selector: "edge",
          style: {
            width: 4,
            "line-color": "#9db3d6",
            "curve-style": "bezier",
            opacity: 0.92,
          },
        },
        {
          selector: ".is-source",
          style: {
            "background-color": "#dbeafe",
            "border-color": "#0f4c81",
            color: "#0f4c81",
          },
        },
        {
          selector: ".is-visited",
          style: {
            "background-color": "#4f76b8",
            "border-color": "#163b73",
            color: "#ffffff",
          },
        },
        {
          selector: ".is-current",
          style: {
            "background-color": "#f59e0b",
            "border-color": "#b45309",
            color: "#ffffff",
          },
        },
        {
          selector: ".is-tree-edge",
          style: {
            width: 6,
            "line-color": "#2563eb",
          },
        },
      ],
    });
  }

  function setRunning(root, running) {
    root.querySelectorAll("button, select").forEach((element) => {
      element.disabled = running;
    });
  }

  async function animate(root, cy, result, source, runToken) {
    const nodes = GRAPH.nodes.map((node) => node.id);
    const invariantEl = root.querySelector('[data-role="invariant"]');
    const frontierEl = root.querySelector('[data-role="frontier"]');
    const orderEl = root.querySelector('[data-role="order"]');
    const metricEl = root.querySelector('[data-role="metric"]');
    const parentEl = root.querySelector('[data-role="parent"]');
    const noteEl = root.querySelector('[data-role="note"]');

    cy.nodes().removeClass("is-visited is-current is-source");
    cy.edges().removeClass("is-tree-edge");
    cy.$id(source).addClass("is-source");

    orderEl.textContent = "-";
    metricEl.textContent = "-";
    parentEl.textContent = "-";
    frontierEl.textContent = result.frontierLabel + ": " + source;
    invariantEl.textContent = result.order.length ? result.frontierLabel === "Queue"
      ? "BFS fixes shortest unweighted distance when a node is first pushed into the queue."
      : "DFS keeps one active search branch visible through the recursion stack."
      : "-";
    noteEl.textContent = "Watch how the traversal frontier changes after each committed visit.";

    for (let i = 0; i < result.order.length; i += 1) {
      if (root.dataset.runToken !== runToken) {
        return;
      }

      const nodeId = result.order[i];
      cy.nodes().removeClass("is-current");
      const currentNode = cy.$id(nodeId);
      currentNode.addClass("is-visited is-current");

      const parentId = result.parent[nodeId];
      if (parentId && parentId !== "-") {
        const edgeId = `${parentId}-${nodeId}`;
        const reverseId = `${nodeId}-${parentId}`;
        const edge = cy.$id(edgeId).length ? cy.$id(edgeId) : cy.$id(reverseId);
        edge.addClass("is-tree-edge");
      }

      const seenOrder = result.order.slice(0, i + 1);
      orderEl.textContent = seenOrder.join(" -> ");
      metricEl.textContent = `${result.metricLabel}: ` + formatMap(seenOrder, result.metric);
      parentEl.textContent = "Parent: " + formatMap(seenOrder, result.parent);

      const step = result.steps[i];
      frontierEl.textContent =
        result.frontierLabel + ": " + (step.frontier.length ? step.frontier.join(" -> ") : "empty");
      invariantEl.textContent = step.invariant;
      noteEl.textContent = step.note;

      await new Promise((resolve) => window.setTimeout(resolve, 800));
    }

    if (root.dataset.runToken !== runToken) {
      return;
    }

    cy.nodes().removeClass("is-current");
    frontierEl.textContent = result.frontierLabel + ": empty";
    noteEl.textContent = "The final tree edges show the traversal structure committed by the chosen invariant.";
  }

  async function runTraversal(root, cy, type) {
    const source = root.querySelector('[data-role="source"]').value;
    const adj = buildAdjacency();
    const result = type === "bfs" ? bfs(source, adj) : dfs(source, adj);
    const token = `${Date.now()}-${type}`;
    root.dataset.runToken = token;

    root.querySelectorAll('[data-role="run-bfs"], [data-role="run-dfs"]').forEach((button) => {
      button.classList.remove("is-active");
    });
    root.querySelector(`[data-role="run-${type}"]`).classList.add("is-active");
    setRunning(root, true);
    root.querySelector('[data-role="reset"]').disabled = false;
    try {
      await animate(root, cy, result, source, token);
    } finally {
      if (root.dataset.runToken === token) {
        setRunning(root, false);
        root.querySelector(`[data-role="run-${type}"]`).classList.add("is-active");
      }
    }
  }

  function reset(root, cy) {
    root.dataset.runToken = "";
    root.querySelectorAll("button").forEach((button) => {
      button.classList.remove("is-active");
      button.disabled = false;
    });
    root.querySelector("select").disabled = false;

    cy.nodes().removeClass("is-visited is-current is-source");
    cy.edges().removeClass("is-tree-edge");

    const source = root.querySelector('[data-role="source"]').value;
    cy.$id(source).addClass("is-source");

    root.querySelector('[data-role="invariant"]').textContent =
      "Pick BFS when the statement cares about unweighted shortest distance; pick DFS when it cares about search structure.";
    root.querySelector('[data-role="frontier"]').textContent = "Queue / active branch: waiting to run";
    root.querySelector('[data-role="order"]').textContent = "-";
    root.querySelector('[data-role="metric"]').textContent = "-";
    root.querySelector('[data-role="parent"]').textContent = "-";
    root.querySelector('[data-role="note"]').textContent =
      "The adjacency order is alphabetical so the BFS and DFS orders are deterministic.";
  }

  async function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    try {
      await loadCytoscape();
    } catch (error) {
      root.innerHTML = `<p><strong>Visualization unavailable:</strong> ${error.message}</p>`;
      return;
    }

    const cy = createGraph(root.querySelector('[data-role="canvas"]'));

    root.querySelector('[data-role="run-bfs"]').addEventListener("click", () => {
      runTraversal(root, cy, "bfs");
    });
    root.querySelector('[data-role="run-dfs"]').addEventListener("click", () => {
      runTraversal(root, cy, "dfs");
    });
    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(root, cy);
    });
    root.querySelector('[data-role="source"]').addEventListener("change", () => {
      reset(root, cy);
    });

    reset(root, cy);
  }

  function boot() {
    document.querySelectorAll("[data-bfs-dfs-visualizer]").forEach(initOne);
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
