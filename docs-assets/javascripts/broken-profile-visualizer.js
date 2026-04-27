(() => {
  const HEIGHT = 3;
  const WIDTH = 900;
  const SVG_HEIGHT = 330;
  const CELL = 74;
  const GAP = 16;
  const LEFT_X = 170;
  const RIGHT_X = LEFT_X + CELL + GAP;
  const TOP_Y = 100;

  function formatMask(mask) {
    const bits = [];
    for (let row = 0; row < HEIGHT; row += 1) {
      bits.push((mask & (1 << row)) !== 0 ? "1" : "0");
    }
    return `${bits.join("")}_2`;
  }

  function generateTransitions(mask) {
    const results = [];

    function dfs(row, nextMask, steps) {
      if (row === HEIGHT) {
        results.push({ nextMask, steps });
        return;
      }

      if (mask & (1 << row)) {
        dfs(row + 1, nextMask, steps.concat({ type: "skip", row }));
        return;
      }

      dfs(row + 1, nextMask | (1 << row), steps.concat({ type: "horizontal", row }));

      if (row + 1 < HEIGHT && !(mask & (1 << (row + 1)))) {
        dfs(row + 2, nextMask, steps.concat({ type: "vertical", row }));
      }
    }

    dfs(0, 0, []);
    return results;
  }

  const TRANSITIONS = Array.from({ length: 1 << HEIGHT }, (_, mask) => generateTransitions(mask));

  function stepLabel(step) {
    if (step.type === "skip") {
      return `row ${step.row} already filled -> move on`;
    }
    if (step.type === "horizontal") {
      return `place horizontal at row ${step.row} -> set bit ${step.row} in next_mask`;
    }
    return `place vertical at rows ${step.row} and ${step.row + 1} -> next_mask unchanged`;
  }

  function replay(mask, transition, stepCount) {
    const frames = {
      currentFilled: Array.from({ length: HEIGHT }, (_, row) => (mask & (1 << row)) !== 0),
      nextFilled: Array.from({ length: HEIGHT }, () => false),
      horizontalRows: new Set(),
      verticalRows: new Set(),
      resolved: Array.from({ length: HEIGHT }, () => false),
      pointer: 0,
      partialNextMask: 0,
      lastAction: "No transition step applied yet.",
    };

    for (let i = 0; i < stepCount; i += 1) {
      const step = transition.steps[i];
      frames.lastAction = stepLabel(step);
      if (step.type === "skip") {
        frames.resolved[step.row] = true;
      } else if (step.type === "horizontal") {
        frames.resolved[step.row] = true;
        frames.horizontalRows.add(step.row);
        frames.nextFilled[step.row] = true;
        frames.partialNextMask |= 1 << step.row;
      } else {
        frames.resolved[step.row] = true;
        frames.resolved[step.row + 1] = true;
        frames.verticalRows.add(step.row);
      }
    }

    let pointer = 0;
    while (pointer < HEIGHT && frames.resolved[pointer]) {
      pointer += 1;
    }
    frames.pointer = pointer;
    return frames;
  }

  function makeState() {
    return {
      mask: 0,
      transitionIndex: 0,
      stepIndex: 0,
    };
  }

  function currentTransition(state) {
    const transitions = TRANSITIONS[state.mask];
    return transitions[Math.min(state.transitionIndex, transitions.length - 1)];
  }

  function currentFrames(state) {
    return replay(state.mask, currentTransition(state), state.stepIndex);
  }

  function renderCanvas(root, state) {
    const host = root.querySelector('[data-role="canvas"]');
    host.innerHTML = "";

    const transition = currentTransition(state);
    const frame = currentFrames(state);

    const svg = d3
      .select(host)
      .append("svg")
      .attr("viewBox", `0 0 ${WIDTH} ${SVG_HEIGHT}`)
      .attr("class", "broken-profile-svg")
      .attr("role", "img")
      .attr("aria-label", "Broken profile current frontier and next frontier visualizer");

    svg
      .append("text")
      .attr("class", "broken-profile-title")
      .attr("x", WIDTH / 2)
      .attr("y", 34)
      .attr("text-anchor", "middle")
      .text("Generate one legal next frontier from the current mask");

    svg
      .append("text")
      .attr("class", "broken-profile-subtitle")
      .attr("x", WIDTH / 2)
      .attr("y", 58)
      .attr("text-anchor", "middle")
      .text(`current mask = ${formatMask(state.mask)} | branch ${state.transitionIndex + 1}/${TRANSITIONS[state.mask].length}`);

    const panelTitles = [
      { x: LEFT_X + CELL / 2, text: "current column" },
      { x: RIGHT_X + CELL / 2, text: "next column" },
    ];
    panelTitles.forEach(({ x, text }) => {
      svg
        .append("text")
        .attr("class", "broken-profile-col-label")
        .attr("x", x)
        .attr("y", TOP_Y - 22)
        .attr("text-anchor", "middle")
        .text(text);
    });

    for (let row = 0; row < HEIGHT; row += 1) {
      svg
        .append("text")
        .attr("class", "broken-profile-row-label")
        .attr("x", LEFT_X - 24)
        .attr("y", TOP_Y + row * CELL + CELL / 2 + 6)
        .attr("text-anchor", "end")
        .text(`r${row}`);

      [
        { x: LEFT_X, type: "current" },
        { x: RIGHT_X, type: "next" },
      ].forEach(({ x, type }) => {
        const classes = ["broken-profile-cell"];
        if (type === "current") {
          if (frame.currentFilled[row]) {
            classes.push("is-pre-filled");
          }
          if (frame.horizontalRows.has(row)) {
            classes.push("is-horizontal");
          }
          if (Array.from(frame.verticalRows).some((topRow) => row === topRow || row === topRow + 1)) {
            classes.push("is-vertical");
          }
          if (frame.pointer === row) {
            classes.push("is-pointer");
          }
        } else {
          if (frame.nextFilled[row]) {
            classes.push("is-next-filled");
          }
        }
        if (frame.resolved[row]) {
          classes.push("is-resolved");
        }

        svg
          .append("rect")
          .attr("class", classes.join(" "))
          .attr("x", x)
          .attr("y", TOP_Y + row * CELL)
          .attr("width", CELL)
          .attr("height", CELL)
          .attr("rx", 18);

        svg
          .append("text")
          .attr("class", "broken-profile-cell-value")
          .attr("x", x + CELL / 2)
          .attr("y", TOP_Y + row * CELL + 30)
          .attr("text-anchor", "middle")
          .text(
            type === "current"
              ? frame.currentFilled[row]
                ? "filled"
                : "open"
              : frame.nextFilled[row]
                ? "bit 1"
                : "bit 0",
          );

        svg
          .append("text")
          .attr("class", "broken-profile-cell-sub")
          .attr("x", x + CELL / 2)
          .attr("y", TOP_Y + row * CELL + 54)
          .attr("text-anchor", "middle")
          .text(
            type === "current"
              ? frame.horizontalRows.has(row)
                ? "to next col"
                : Array.from(frame.verticalRows).some((topRow) => row === topRow || row === topRow + 1)
                  ? "same column"
                  : frame.currentFilled[row]
                    ? "from left"
                    : "unresolved"
              : frame.nextFilled[row]
                ? "reserved"
                : "free",
          );
      });
    }

    Array.from(frame.verticalRows).forEach((topRow) => {
      svg
        .append("rect")
        .attr("class", "broken-profile-overlay is-vertical")
        .attr("x", LEFT_X + 9)
        .attr("y", TOP_Y + topRow * CELL + 9)
        .attr("width", CELL - 18)
        .attr("height", CELL * 2 - 18)
        .attr("rx", 14);
    });

    Array.from(frame.horizontalRows).forEach((row) => {
      svg
        .append("rect")
        .attr("class", "broken-profile-overlay is-horizontal")
        .attr("x", LEFT_X + 9)
        .attr("y", TOP_Y + row * CELL + 14)
        .attr("width", RIGHT_X - LEFT_X + CELL - 18)
        .attr("height", CELL - 28)
        .attr("rx", 14);
    });

    if (frame.pointer < HEIGHT) {
      const pointerY = TOP_Y + frame.pointer * CELL + CELL / 2;
      svg
        .append("line")
        .attr("class", "broken-profile-pointer")
        .attr("x1", LEFT_X - 86)
        .attr("x2", LEFT_X - 8)
        .attr("y1", pointerY)
        .attr("y2", pointerY);

      svg
        .append("text")
        .attr("class", "broken-profile-pointer-label")
        .attr("x", LEFT_X - 92)
        .attr("y", pointerY + 6)
        .attr("text-anchor", "end")
        .text("scan row");
    }

    const actions = transition.steps.map((step, index) =>
      `${index < state.stepIndex ? "done" : index === state.stepIndex ? "next" : "later"}: ${stepLabel(step)}`,
    );

    root.querySelector('[data-role="actions"]').innerHTML = actions.map((line) => `<li>${line}</li>`).join("");
  }

  function renderSummary(root, state) {
    const transition = currentTransition(state);
    const frame = currentFrames(state);
    const completed = state.stepIndex === transition.steps.length;

    root.querySelector('[data-role="invariant"]').textContent =
      "Above the scan pointer, the current column is already completely resolved. Horizontal placements write bits into next_mask; vertical placements stay inside the current column.";
    root.querySelector('[data-role="mask"]').textContent = `cur_mask = ${formatMask(state.mask)}`;
    root.querySelector('[data-role="branch"]').textContent = `${state.transitionIndex + 1}/${TRANSITIONS[state.mask].length}`;
    root.querySelector('[data-role="partial"]').textContent = `${completed ? "final" : "partial"} next_mask = ${formatMask(frame.partialNextMask)}`;
    root.querySelector('[data-role="result"]').textContent = completed
      ? `Finished branch -> legal next_mask ${formatMask(transition.nextMask)}`
      : frame.lastAction;
    root.querySelector('[data-role="note"]').textContent = completed
      ? "This single legal completion contributes one transition to dp_next[next_mask]. The full DP sums over all such completions."
      : "Step through the branch to see exactly when a cell is skipped, when a vertical domino stays local, and when a horizontal domino reserves a bit in the next frontier.";
  }

  function rerender(root, state) {
    const transitions = TRANSITIONS[state.mask];
    if (state.transitionIndex >= transitions.length) {
      state.transitionIndex = 0;
    }
    const transition = currentTransition(state);
    if (state.stepIndex > transition.steps.length) {
      state.stepIndex = transition.steps.length;
    }

    const branchSelect = root.querySelector('[data-role="branch-select"]');
    branchSelect.innerHTML = transitions
      .map(
        (item, index) =>
          `<option value="${index}">branch ${index + 1}: next_mask = ${formatMask(item.nextMask)}</option>`,
      )
      .join("");
    branchSelect.value = String(state.transitionIndex);

    renderCanvas(root, state);
    renderSummary(root, state);
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const state = makeState();

    const maskSelect = root.querySelector('[data-role="mask-select"]');
    maskSelect.innerHTML = Array.from({ length: 1 << HEIGHT }, (_, mask) => {
      return `<option value="${mask}">${formatMask(mask)}</option>`;
    }).join("");
    maskSelect.value = "0";

    root.querySelector('[data-role="next-step"]').addEventListener("click", () => {
      const transition = currentTransition(state);
      if (state.stepIndex < transition.steps.length) {
        state.stepIndex += 1;
      }
      rerender(root, state);
    });

    root.querySelector('[data-role="prev-step"]').addEventListener("click", () => {
      if (state.stepIndex > 0) {
        state.stepIndex -= 1;
      }
      rerender(root, state);
    });

    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      state.stepIndex = 0;
      rerender(root, state);
    });

    root.querySelector('[data-role="mask-select"]').addEventListener("change", (event) => {
      state.mask = Number(event.target.value);
      state.transitionIndex = 0;
      state.stepIndex = 0;
      rerender(root, state);
    });

    root.querySelector('[data-role="branch-select"]').addEventListener("change", (event) => {
      state.transitionIndex = Number(event.target.value);
      state.stepIndex = 0;
      rerender(root, state);
    });

    rerender(root, state);
  }

  function boot() {
    document.querySelectorAll("[data-broken-profile-visualizer]").forEach(initOne);
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
