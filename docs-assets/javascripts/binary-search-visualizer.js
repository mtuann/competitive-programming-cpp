(() => {
  const DOMAIN_MAX = 15;
  const DOMAIN = Array.from({ length: DOMAIN_MAX + 1 }, (_, index) => index);
  const WIDTH = 860;
  const HEIGHT = 250;
  const MARGIN = { top: 44, right: 24, bottom: 74, left: 24 };
  const CELL_GAP = 8;

  function makeInitialState(target) {
    return {
      target,
      l: -1,
      r: DOMAIN_MAX + 1,
      mid: null,
      lastDecision: "The invariant starts as: l is bad, r is good, and the first good answer lies in (l, r].",
      running: false,
      done: false,
    };
  }

  function firstGood(state) {
    return state.target;
  }

  function isGood(state, value) {
    return value >= state.target;
  }

  function wait(ms) {
    return new Promise((resolve) => {
      window.setTimeout(resolve, ms);
    });
  }

  function render(root, state) {
    const host = root.querySelector('[data-role="canvas"]');
    host.innerHTML = "";

    const svg = d3
      .select(host)
      .append("svg")
      .attr("viewBox", `0 0 ${WIDTH} ${HEIGHT}`)
      .attr("class", "binary-search-svg")
      .attr("role", "img")
      .attr("aria-label", "Binary search interval visualizer");

    const innerWidth = WIDTH - MARGIN.left - MARGIN.right;
    const cellWidth = (innerWidth - CELL_GAP * (DOMAIN.length - 1)) / DOMAIN.length;
    const y = 76;
    const rectHeight = 68;
    const xAt = (index) => MARGIN.left + index * (cellWidth + CELL_GAP);

    const candidateLeft = state.l + 1;
    const candidateRight = state.r - 1;
    const hasCandidateBand = candidateLeft <= candidateRight;

    if (hasCandidateBand) {
      svg
        .append("rect")
        .attr("class", "binary-search-window")
        .attr("x", xAt(candidateLeft) - 6)
        .attr("y", y - 14)
        .attr("width", xAt(candidateRight) + cellWidth - xAt(candidateLeft) + 12)
        .attr("height", rectHeight + 28)
        .attr("rx", 18);
    }

    const cells = svg
      .append("g")
      .attr("class", "binary-search-cells")
      .selectAll("g")
      .data(DOMAIN)
      .enter()
      .append("g")
      .attr("transform", (d) => `translate(${xAt(d)}, ${y})`);

    cells
      .append("rect")
      .attr("rx", 16)
      .attr("width", cellWidth)
      .attr("height", rectHeight)
      .attr("class", (d) => {
        const classes = ["binary-search-cell"];
        classes.push(isGood(state, d) ? "is-good" : "is-bad");
        if (d <= state.l || d > state.r) {
          classes.push("is-eliminated");
        } else {
          classes.push("is-candidate");
        }
        if (state.mid === d) {
          classes.push("is-mid");
        }
        if (d === firstGood(state)) {
          classes.push("is-answer");
        }
        return classes.join(" ");
      });

    cells
      .append("text")
      .attr("class", "binary-search-cell-value")
      .attr("x", cellWidth / 2)
      .attr("y", 28)
      .attr("text-anchor", "middle")
      .text((d) => d);

    cells
      .append("text")
      .attr("class", "binary-search-cell-predicate")
      .attr("x", cellWidth / 2)
      .attr("y", 52)
      .attr("text-anchor", "middle")
      .text((d) => (isGood(state, d) ? "good" : "bad"));

    cells
      .append("text")
      .attr("class", "binary-search-cell-index")
      .attr("x", cellWidth / 2)
      .attr("y", rectHeight + 26)
      .attr("text-anchor", "middle")
      .text((d) => `x=${d}`);

    const markers = [
      { label: `l = ${state.l}`, index: Math.max(state.l, 0), offset: state.l < 0 ? -20 : 0, className: "is-left" },
      { label: `r = ${state.r}`, index: Math.min(state.r, DOMAIN_MAX), offset: state.r > DOMAIN_MAX ? 20 : 0, className: "is-right" },
    ];

    if (state.mid !== null) {
      markers.push({ label: `mid = ${state.mid}`, index: state.mid, offset: 0, className: "is-mid" });
    }

    const markerLayer = svg.append("g").attr("class", "binary-search-markers");

    markers.forEach((marker) => {
      const x = xAt(marker.index) + cellWidth / 2 + marker.offset;
      markerLayer
        .append("line")
        .attr("class", `binary-search-pointer ${marker.className}`)
        .attr("x1", x)
        .attr("x2", x)
        .attr("y1", 24)
        .attr("y2", y - 6);

      markerLayer
        .append("text")
        .attr("class", `binary-search-pointer-label ${marker.className}`)
        .attr("x", x)
        .attr("y", 18)
        .attr("text-anchor", "middle")
        .text(marker.label);
    });

    const boundaryX = xAt(state.target) - CELL_GAP / 2;
    svg
      .append("line")
      .attr("class", "binary-search-boundary")
      .attr("x1", boundaryX)
      .attr("x2", boundaryX)
      .attr("y1", y - 20)
      .attr("y2", y + rectHeight + 10);

    root.querySelector('[data-role="invariant"]').textContent =
      "Maintain l as a known bad state and r as a known good state. The first good answer always stays in (l, r].";
    root.querySelector('[data-role="interval"]').textContent =
      state.done
        ? `Loop finished with r = ${state.r} and l = ${state.l}. Because r = l + 1, r is the first good answer.`
        : `Current candidate interval: (${state.l}, ${state.r}]`;
    root.querySelector('[data-role="decision"]').textContent = state.lastDecision;
    root.querySelector('[data-role="result"]').textContent = state.done
      ? `first good = ${state.r}`
      : state.mid === null
        ? "waiting to start"
        : `mid = ${state.mid}, good(mid) = ${isGood(state, state.mid)}`;
    root.querySelector('[data-role="note"]').textContent =
      `The hidden boundary is at x = ${state.target}: all candidates before it are bad, and all candidates from it onward are good.`;
  }

  function reset(root, state) {
    const target = Number(root.querySelector('[data-role="target"]').value);
    Object.assign(state, makeInitialState(target));
    root.querySelector('[data-role="step"]').disabled = false;
    root.querySelector('[data-role="run"]').disabled = false;
    root.querySelector('[data-role="target"]').disabled = false;
    render(root, state);
  }

  function step(root, state) {
    if (state.done) {
      return;
    }

    if (state.r - state.l <= 1) {
      state.done = true;
      state.lastDecision = "The interval has collapsed to adjacent sentinels, so r is the first good answer.";
      render(root, state);
      return;
    }

    state.mid = Math.floor((state.l + state.r) / 2);

    if (isGood(state, state.mid)) {
      state.lastDecision = `good(${state.mid}) is true, so the first good answer cannot lie to the right of ${state.mid}. Keep (l, mid].`;
      state.r = state.mid;
    } else {
      state.lastDecision = `good(${state.mid}) is false, so the first good answer cannot lie at or to the left of ${state.mid}. Keep (mid, r].`;
      state.l = state.mid;
    }

    if (state.r - state.l <= 1) {
      state.done = true;
      state.lastDecision += " The interval is now adjacent, so r is the answer.";
      root.querySelector('[data-role="step"]').disabled = true;
      root.querySelector('[data-role="run"]').disabled = true;
    }

    render(root, state);
  }

  async function run(root, state) {
    if (state.running) {
      return;
    }

    state.running = true;
    root.querySelector('[data-role="step"]').disabled = true;
    root.querySelector('[data-role="run"]').disabled = true;
    root.querySelector('[data-role="target"]').disabled = true;

    while (!state.done) {
      step(root, state);
      if (!state.done) {
        await wait(760);
      }
    }

    state.running = false;
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const state = makeInitialState(Number(root.querySelector('[data-role="target"]').value));

    root.querySelector('[data-role="step"]').addEventListener("click", () => {
      step(root, state);
    });
    root.querySelector('[data-role="run"]').addEventListener("click", () => {
      void run(root, state);
    });
    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(root, state);
    });
    root.querySelector('[data-role="target"]').addEventListener("change", () => {
      reset(root, state);
    });

    render(root, state);
  }

  function boot() {
    document.querySelectorAll("[data-binary-search-visualizer]").forEach(initOne);
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
