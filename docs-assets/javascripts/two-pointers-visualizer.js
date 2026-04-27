(() => {
  const VALUES = [2, 1, 3, 2, 1, 1, 4, 2];
  const WIDTH = 900;
  const HEIGHT = 220;
  const CELL_WIDTH = 92;
  const CELL_HEIGHT = 68;
  const LEFT_PAD = 72;
  const TOP_PAD = 84;

  function makeState(limit = 6) {
    return {
      limit,
      l: 0,
      nextR: 0,
      sum: 0,
      phase: "expand",
      done: false,
      bestLen: 0,
      bestRange: null,
      lastAdded: null,
      lastRemoved: null,
      actionText: "Ready to scan a nonnegative array with sum <= K.",
    };
  }

  function formatWindow(state) {
    return `[${state.l}, ${state.nextR})`;
  }

  function currentWindowLength(state) {
    return state.nextR - state.l;
  }

  function updateBest(state) {
    if (state.sum <= state.limit) {
      const len = currentWindowLength(state);
      if (len > state.bestLen) {
        state.bestLen = len;
        state.bestRange = [state.l, state.nextR];
      }
    }
  }

  function renderCanvas(root, state) {
    const host = root.querySelector('[data-role="canvas"]');
    host.innerHTML = "";

    const svg = d3
      .select(host)
      .append("svg")
      .attr("viewBox", `0 0 ${WIDTH} ${HEIGHT}`)
      .attr("class", "two-pointers-svg")
      .attr("role", "img")
      .attr("aria-label", "Two pointers sliding window visualizer");

    const cells = VALUES.map((value, index) => ({
      index,
      value,
      x: LEFT_PAD + index * CELL_WIDTH,
      y: TOP_PAD,
    }));

    const windowValid = state.sum <= state.limit;
    const windowStartX = LEFT_PAD + state.l * CELL_WIDTH;
    const windowWidth = Math.max(0, (state.nextR - state.l) * CELL_WIDTH);

    if (windowWidth > 0) {
      svg
        .append("rect")
        .attr("class", windowValid ? "two-pointers-window is-valid" : "two-pointers-window is-invalid")
        .attr("x", windowStartX - 8)
        .attr("y", TOP_PAD - 12)
        .attr("width", windowWidth + 16)
        .attr("height", CELL_HEIGHT + 24)
        .attr("rx", 18);
    }

    const groups = svg
      .append("g")
      .selectAll("g")
      .data(cells)
      .enter()
      .append("g")
      .attr("transform", (d) => `translate(${d.x}, ${d.y})`);

    groups
      .append("rect")
      .attr("class", (d) => {
        const classes = ["two-pointers-cell"];
        if (state.l <= d.index && d.index < state.nextR) {
          classes.push(windowValid ? "is-in-window" : "is-in-invalid-window");
        } else {
          classes.push("is-outside");
        }
        if (state.lastAdded === d.index) {
          classes.push("is-added");
        }
        if (state.lastRemoved === d.index) {
          classes.push("is-removed");
        }
        return classes.join(" ");
      })
      .attr("width", CELL_WIDTH - 10)
      .attr("height", CELL_HEIGHT)
      .attr("rx", 18);

    groups
      .append("text")
      .attr("class", "two-pointers-cell-index")
      .attr("x", (CELL_WIDTH - 10) / 2)
      .attr("y", 20)
      .attr("text-anchor", "middle")
      .text((d) => `idx ${d.index}`);

    groups
      .append("text")
      .attr("class", "two-pointers-cell-value")
      .attr("x", (CELL_WIDTH - 10) / 2)
      .attr("y", 47)
      .attr("text-anchor", "middle")
      .text((d) => d.value);

    const pointerLayer = svg.append("g").attr("class", "two-pointers-pointers");

    if (state.l < VALUES.length) {
      const lx = LEFT_PAD + state.l * CELL_WIDTH + (CELL_WIDTH - 10) / 2;
      pointerLayer
        .append("line")
        .attr("class", "two-pointers-pointer is-left")
        .attr("x1", lx)
        .attr("y1", TOP_PAD - 38)
        .attr("x2", lx)
        .attr("y2", TOP_PAD - 6);

      pointerLayer
        .append("text")
        .attr("class", "two-pointers-pointer-label is-left")
        .attr("x", lx)
        .attr("y", TOP_PAD - 46)
        .attr("text-anchor", "middle")
        .text("l");
    }

    const nextBoundaryX = LEFT_PAD + state.nextR * CELL_WIDTH;
    pointerLayer
      .append("line")
      .attr("class", "two-pointers-pointer is-right")
      .attr("x1", nextBoundaryX)
      .attr("y1", TOP_PAD + CELL_HEIGHT + 10)
      .attr("x2", nextBoundaryX)
      .attr("y2", TOP_PAD + CELL_HEIGHT + 42);

    pointerLayer
      .append("text")
      .attr("class", "two-pointers-pointer-label is-right")
      .attr("x", nextBoundaryX)
      .attr("y", TOP_PAD + CELL_HEIGHT + 60)
      .attr("text-anchor", "middle")
      .text(state.nextR < VALUES.length ? "next r" : "done");
  }

  function renderSummary(root, state) {
    const invariant =
      state.phase === "expand"
        ? "Window is valid, and r is the next unseen index. Expanding tests the next candidate ending position."
        : "Window is currently invalid. Only moving l right can repair sum <= K because every value is nonnegative.";

    root.querySelector('[data-role="invariant"]').textContent = invariant;
    root.querySelector('[data-role="phase"]').textContent =
      state.done ? "finished" : state.phase;
    root.querySelector('[data-role="window"]').textContent = `${formatWindow(state)} | sum = ${state.sum}`;
    root.querySelector('[data-role="best"]').textContent =
      state.bestRange === null
        ? "No valid window recorded yet."
        : `[${state.bestRange[0]}, ${state.bestRange[1]}) | length = ${state.bestLen}`;
    root.querySelector('[data-role="result"]').textContent = state.actionText;
    root.querySelector('[data-role="note"]').textContent =
      "The proof works because extending right never decreases the sum, and removing from the left never increases it.";
  }

  function rerender(root, state) {
    renderCanvas(root, state);
    renderSummary(root, state);
  }

  function step(state) {
    state.lastAdded = null;
    state.lastRemoved = null;

    if (state.done) {
      state.actionText = "Traversal already finished. Reset to replay the window evolution.";
      return;
    }

    if (state.phase === "expand") {
      if (state.nextR >= VALUES.length) {
        state.done = true;
        state.actionText = "All right endpoints have been processed.";
        return;
      }

      const idx = state.nextR;
      state.sum += VALUES[idx];
      state.nextR += 1;
      state.lastAdded = idx;

      if (state.sum <= state.limit) {
        updateBest(state);
        state.actionText = `Added a[${idx}] = ${VALUES[idx]}. Window stayed valid, so [l, r) is a candidate answer.`;
      } else {
        state.phase = "shrink";
        state.actionText = `Added a[${idx}] = ${VALUES[idx]}. Window became invalid, so the loop must move l right.`;
      }
      return;
    }

    const removed = state.l;
    state.sum -= VALUES[removed];
    state.l += 1;
    state.lastRemoved = removed;

    if (state.sum <= state.limit) {
      state.phase = "expand";
      updateBest(state);
      state.actionText = `Removed a[${removed}] = ${VALUES[removed]}. Window is valid again, so the repaired interval becomes the candidate ending at the current right boundary.`;
    } else {
      state.actionText = `Removed a[${removed}] = ${VALUES[removed]}, but sum is still too large. Keep shrinking from the left.`;
    }
  }

  function reset(root, state) {
    const limit = Number(root.querySelector('[data-role="limit"]').value);
    const fresh = makeState(limit);
    Object.assign(state, fresh);
    rerender(root, state);
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const state = makeState(Number(root.querySelector('[data-role="limit"]').value));

    root.querySelector('[data-role="step"]').addEventListener("click", () => {
      step(state);
      rerender(root, state);
    });

    root.querySelector('[data-role="run"]').addEventListener("click", () => {
      let guard = 0;
      while (!state.done && guard < 64) {
        step(state);
        guard += 1;
      }
      rerender(root, state);
    });

    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(root, state);
    });

    root.querySelector('[data-role="limit"]').addEventListener("change", () => {
      reset(root, state);
    });

    rerender(root, state);
  }

  function boot() {
    document.querySelectorAll("[data-two-pointers-visualizer]").forEach(initOne);
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
