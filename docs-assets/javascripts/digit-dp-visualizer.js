(() => {
  const BOUND = "325";
  const DIGITS = BOUND.split("").map(Number);
  const WIDTH = 920;
  const HEIGHT = 330;
  const ROOT_X = WIDTH / 2;
  const ROOT_Y = 86;
  const BOX_W = 92;
  const BOX_H = 70;
  const CHILD_Y = 210;

  function makeState() {
    return {
      pos: 0,
      tight: true,
      started: false,
      prev: null,
      chosen: [],
      history: [],
      lastAction: `Start at dp(pos=0, tight=1, started=0, prev=none) for upper bound ${BOUND}.`,
    };
  }

  function formatPrefix(chosen) {
    return chosen.length === 0 ? "[]" : `[${chosen.join(" ")}]`;
  }

  function renderedNumber(chosen) {
    const asText = chosen.join("").replace(/^0+/, "");
    return asText === "" ? "0" : asText;
  }

  function stateSummary(state) {
    return `pos=${state.pos}, tight=${state.tight ? 1 : 0}, started=${state.started ? 1 : 0}, prev=${state.prev === null ? "-" : state.prev}`;
  }

  function candidates(state) {
    if (state.pos >= DIGITS.length) {
      return [];
    }

    const limit = state.tight ? DIGITS[state.pos] : 9;
    const items = [];
    for (let d = 0; d <= limit; d += 1) {
      const nextStarted = state.started || d !== 0;
      const invalidAdj = state.started && d === state.prev;
      const nextTight = state.tight && d === DIGITS[state.pos];
      const nextPrev = nextStarted ? d : null;
      const nextChosen = state.chosen.concat(d);

      let reason = "valid branch";
      if (invalidAdj) {
        reason = "pruned: adjacent equal real digits";
      } else if (!state.started && d === 0) {
        reason = "still leading zeros, so started stays 0";
      } else if (nextTight) {
        reason = "still glued to the upper bound";
      } else if (state.tight) {
        reason = "strictly below the bound now, so future digits are free";
      } else {
        reason = "already free from the upper bound";
      }

      items.push({
        digit: d,
        valid: !invalidAdj,
        reason,
        nextState: {
          pos: state.pos + 1,
          tight: nextTight,
          started: nextStarted,
          prev: nextPrev,
          chosen: nextChosen,
        },
      });
    }
    return items;
  }

  function renderBound(root, state) {
    const host = root.querySelector('[data-role="bound-strip"]');
    host.innerHTML = DIGITS.map((digit, index) => {
      const classes = ["visual-cell"];
      if (index < state.pos) {
        classes.push("is-processed");
      } else if (index === state.pos && state.pos < DIGITS.length) {
        classes.push("is-current");
      }
      return `
        <div class="${classes.join(" ")}">
          <small>bound[${index}]</small>
          <strong>${digit}</strong>
        </div>
      `;
    }).join("");
  }

  function renderCanvas(root, state) {
    const host = root.querySelector('[data-role="canvas"]');
    host.innerHTML = "";

    const svg = d3
      .select(host)
      .append("svg")
      .attr("viewBox", `0 0 ${WIDTH} ${HEIGHT}`)
      .attr("class", "digit-dp-svg")
      .attr("role", "img")
      .attr("aria-label", "Digit DP state transition visualizer");

    const current = {
      x: ROOT_X - BOX_W / 2,
      y: ROOT_Y,
      label: stateSummary(state),
      prefix: formatPrefix(state.chosen),
    };

    svg
      .append("rect")
      .attr("class", "digit-dp-box is-current-state")
      .attr("x", current.x)
      .attr("y", current.y)
      .attr("width", BOX_W + 56)
      .attr("height", BOX_H + 12)
      .attr("rx", 18);

    svg
      .append("text")
      .attr("class", "digit-dp-box-title")
      .attr("x", ROOT_X)
      .attr("y", current.y + 26)
      .attr("text-anchor", "middle")
      .text("Current state");

    svg
      .append("text")
      .attr("class", "digit-dp-box-main")
      .attr("x", ROOT_X)
      .attr("y", current.y + 49)
      .attr("text-anchor", "middle")
      .text(current.label);

    svg
      .append("text")
      .attr("class", "digit-dp-box-sub")
      .attr("x", ROOT_X)
      .attr("y", current.y + 72)
      .attr("text-anchor", "middle")
      .text(`prefix ${current.prefix}`);

    const options = candidates(state);
    const count = options.length;
    if (count === 0) {
      svg
        .append("rect")
        .attr("class", "digit-dp-box is-terminal-state")
        .attr("x", ROOT_X - 130)
        .attr("y", CHILD_Y)
        .attr("width", 260)
        .attr("height", BOX_H + 8)
        .attr("rx", 18);

      svg
        .append("text")
        .attr("class", "digit-dp-box-title")
        .attr("x", ROOT_X)
        .attr("y", CHILD_Y + 28)
        .attr("text-anchor", "middle")
        .text("Terminal state");

      svg
        .append("text")
        .attr("class", "digit-dp-box-main")
        .attr("x", ROOT_X)
        .attr("y", CHILD_Y + 52)
        .attr("text-anchor", "middle")
        .text(`built number = ${renderedNumber(state.chosen)}`);

      return;
    }

    const childBoxW = count > 6 ? 74 : BOX_W;
    const totalWidth = count * childBoxW + (count - 1) * 10;
    const startX = (WIDTH - totalWidth) / 2;

    options.forEach((option, index) => {
      const x = startX + index * (childBoxW + 10);
      const midX = x + childBoxW / 2;

      svg
        .append("line")
        .attr("class", option.valid ? "digit-dp-link is-valid" : "digit-dp-link is-invalid")
        .attr("x1", ROOT_X)
        .attr("y1", current.y + BOX_H + 12)
        .attr("x2", midX)
        .attr("y2", CHILD_Y - 8);

      svg
        .append("rect")
        .attr("class", option.valid ? "digit-dp-box is-valid-choice" : "digit-dp-box is-invalid-choice")
        .attr("x", x)
        .attr("y", CHILD_Y)
        .attr("width", childBoxW)
        .attr("height", BOX_H + 28)
        .attr("rx", 16);

      svg
        .append("text")
        .attr("class", "digit-dp-box-title")
        .attr("x", midX)
        .attr("y", CHILD_Y + 22)
        .attr("text-anchor", "middle")
        .text(`pick ${option.digit}`);

      svg
        .append("text")
        .attr("class", "digit-dp-box-main")
        .attr("x", midX)
        .attr("y", CHILD_Y + 46)
        .attr("text-anchor", "middle")
        .text(`t${option.nextState.tight ? 1 : 0} s${option.nextState.started ? 1 : 0}`);

      svg
        .append("text")
        .attr("class", "digit-dp-box-sub")
        .attr("x", midX)
        .attr("y", CHILD_Y + 67)
        .attr("text-anchor", "middle")
        .text(`prev=${option.nextState.prev === null ? "-" : option.nextState.prev}`);

      svg
        .append("text")
        .attr("class", "digit-dp-box-foot")
        .attr("x", midX)
        .attr("y", CHILD_Y + 88)
        .attr("text-anchor", "middle")
        .text(option.valid ? "click to advance" : "blocked");
    });
  }

  function renderChoices(root, state) {
    const host = root.querySelector('[data-role="choices"]');
    const select = root.querySelector('[data-role="digit"]');
    const options = candidates(state);

    if (select) {
      if (options.length === 0) {
        select.innerHTML = '<option value="">done</option>';
        select.disabled = true;
      } else {
        select.disabled = false;
        select.innerHTML = options
          .map(
            (option) =>
              `<option value="${option.digit}" ${option.valid ? "" : "disabled"}>${option.digit} ${option.valid ? "" : "(blocked)"}</option>`,
          )
          .join("");
      }
    }

    if (options.length === 0) {
      host.innerHTML = `
        <div class="visual-stat">
          <strong>Terminal interpretation</strong>
          <code>${renderedNumber(state.chosen)} is the constructed number. This branch contributes 1 valid number because every prefix choice respected the adjacency rule.</code>
        </div>
      `;
      return;
    }

    host.innerHTML = options
      .map(
        (option) => `
          <div class="visual-stat">
            <strong>Digit ${option.digit}</strong>
            <code>${option.reason}</code>
          </div>
        `,
      )
      .join("");

    host.querySelectorAll(".visual-stat").forEach((card, index) => {
      if (!options[index].valid) {
        card.classList.add("is-invalid-card");
      }
    });
  }

  function renderSummary(root, state) {
    const options = candidates(state);
    const limit = state.pos < DIGITS.length ? (state.tight ? DIGITS[state.pos] : 9) : "-";

    root.querySelector('[data-role="invariant"]').textContent =
      "State means: we have fixed the first pos digits, tight says whether that prefix still equals the bound prefix, started says whether a real digit has appeared, and prev stores the previous real digit for the adjacency rule.";

    root.querySelector('[data-role="state"]').textContent = stateSummary(state);
    root.querySelector('[data-role="prefix"]').textContent =
      `chosen digits = ${formatPrefix(state.chosen)} | interpreted value = ${renderedNumber(state.chosen)}`;
    root.querySelector('[data-role="limit"]').textContent =
      state.pos >= DIGITS.length
        ? "No next digit remains; this branch is complete."
        : `At pos ${state.pos}, the next digit may range from 0 to ${limit}.`;
    root.querySelector('[data-role="result"]').textContent = state.lastAction;
    root.querySelector('[data-role="note"]').textContent =
      options.length === 0
        ? "The branch ended at one fully built valid number. In the full DP, many different prefixes would memoize by state instead of being explored separately again."
        : "Once tight flips to 0, the bound is no longer constraining future digits. The remaining future depends only on the compact state, which is why memoization is legal.";
  }

  function rerender(root, state) {
    renderBound(root, state);
    renderCanvas(root, state);
    renderChoices(root, state);
    renderSummary(root, state);
  }

  function advance(state, digit) {
    const option = candidates(state).find((item) => item.digit === digit);
    if (!option || !option.valid) {
      return;
    }

    state.history.push({
      pos: state.pos,
      tight: state.tight,
      started: state.started,
      prev: state.prev,
      chosen: [...state.chosen],
      lastAction: state.lastAction,
    });

    state.pos = option.nextState.pos;
    state.tight = option.nextState.tight;
    state.started = option.nextState.started;
    state.prev = option.nextState.prev;
    state.chosen = option.nextState.chosen;
    state.lastAction = `Placed digit ${digit}. ${option.reason}.`;
  }

  function undo(state) {
    const prev = state.history.pop();
    if (!prev) {
      return;
    }
    state.pos = prev.pos;
    state.tight = prev.tight;
    state.started = prev.started;
    state.prev = prev.prev;
    state.chosen = prev.chosen;
    state.lastAction = "Undid the last digit choice.";
  }

  function reset(state) {
    Object.assign(state, makeState());
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const state = makeState();

    root.querySelector('[data-role="take"]').addEventListener("click", () => {
      const selected = root.querySelector('[data-role="digit"]').value;
      if (selected === "") {
        return;
      }
      advance(state, Number(selected));
      rerender(root, state);
    });

    root.querySelector('[data-role="undo"]').addEventListener("click", () => {
      undo(state);
      rerender(root, state);
    });

    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(state);
      rerender(root, state);
    });

    rerender(root, state);
  }

  function boot() {
    document.querySelectorAll("[data-digit-dp-visualizer]").forEach(initOne);
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
