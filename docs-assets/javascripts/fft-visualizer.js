(() => {
  const MOD = 17;
  const OMEGA = 4;
  const INPUT = [1, 2, 3, 0];
  const STAGES = [
    {
      title: "Coefficient order",
      subtitle: "Original padded coefficient array",
      values: [1, 2, 3, 0],
      notes: [
        "This is the polynomial A(x) = 1 + 2x + 3x^2.",
        "Before iterative butterflies, the array is permuted into bit-reversed order.",
      ],
      formulas: ["start: [1, 2, 3, 0]"],
      highlightPairs: [],
    },
    {
      title: "Bit-reversed order",
      subtitle: "Leaves laid out for iterative butterflies",
      values: [1, 3, 2, 0],
      notes: [
        "Indices 0,1,2,3 become 0,2,1,3 after reversing two-bit binary indices.",
        "This linearizes the recursion so len = 2 butterflies can run in-place.",
      ],
      formulas: ["bit-reversal: [a0, a2, a1, a3] = [1, 3, 2, 0]"],
      highlightPairs: [],
    },
    {
      title: "Stage len = 2",
      subtitle: "Two butterflies with twiddle = 1",
      values: [4, 15, 2, 2],
      notes: [
        "Each butterfly applies (u, v) -> (u + v, u - v) mod 17.",
        "For the first pair, (1, 3) -> (4, -2) -> (4, 15).",
      ],
      formulas: [
        "(1, 3) -> (1 + 3, 1 - 3) = (4, 15)",
        "(2, 0) -> (2 + 0, 2 - 0) = (2, 2)",
      ],
      highlightPairs: [
        [0, 1],
        [2, 3],
      ],
    },
    {
      title: "Stage len = 4",
      subtitle: "Second butterfly uses twiddle omega = 4",
      values: [6, 6, 2, 7],
      notes: [
        "The first pair still uses w = 1, so (4, 2) -> (6, 2).",
        "The second pair uses w = omega^1 = 4, so v becomes 2 * 4 = 8 before the combine.",
      ],
      formulas: [
        "(4, 2) with w=1 -> (4 + 2, 4 - 2) = (6, 2)",
        "(15, 2) with w=4 -> (15 + 8, 15 - 8) = (6, 7)",
      ],
      highlightPairs: [
        [0, 2],
        [1, 3],
      ],
    },
    {
      title: "Point-value form",
      subtitle: "NTT values A(1), A(4), A(16), A(13)",
      values: [6, 6, 2, 7],
      notes: [
        "These four outputs are the evaluations of A(x) at the 4-th roots of unity modulo 17.",
        "Convolution becomes pointwise multiplication only after both polynomials reach this value form.",
      ],
      formulas: [
        "A(1) = 6, A(4) = 6, A(16) = 2, A(13) = 7",
        "Next step in convolution: multiply these values entrywise with B's transformed values.",
      ],
      highlightPairs: [],
    },
  ];

  const WIDTH = 900;
  const HEIGHT = 260;
  const CELL_W = 118;
  const CELL_H = 70;
  const START_X = 150;
  const Y = 118;

  function makeState() {
    return { stage: 0 };
  }

  function renderCanvas(root, state) {
    const host = root.querySelector('[data-role="canvas"]');
    host.innerHTML = "";
    const stage = STAGES[state.stage];

    const svg = d3
      .select(host)
      .append("svg")
      .attr("viewBox", `0 0 ${WIDTH} ${HEIGHT}`)
      .attr("class", "fft-svg")
      .attr("role", "img")
      .attr("aria-label", "FFT and NTT butterfly stage visualizer");

    svg
      .append("text")
      .attr("class", "fft-stage-title")
      .attr("x", WIDTH / 2)
      .attr("y", 34)
      .attr("text-anchor", "middle")
      .text(stage.title);

    svg
      .append("text")
      .attr("class", "fft-stage-subtitle")
      .attr("x", WIDTH / 2)
      .attr("y", 58)
      .attr("text-anchor", "middle")
      .text(stage.subtitle);

    stage.highlightPairs.forEach(([i, j]) => {
      const x1 = START_X + i * CELL_W + CELL_W / 2;
      const x2 = START_X + j * CELL_W + CELL_W / 2;
      svg
        .append("path")
        .attr("class", "fft-pair-curve")
        .attr("d", `M ${x1} ${Y - 18} C ${x1} ${Y - 62}, ${x2} ${Y - 62}, ${x2} ${Y - 18}`);
    });

    stage.values.forEach((value, index) => {
      const x = START_X + index * CELL_W;
      const classes = ["fft-cell"];
      if (state.stage === 1) {
        classes.push("is-reordered");
      } else if (state.stage >= 2) {
        classes.push("is-stage-value");
      }

      svg
        .append("rect")
        .attr("class", classes.join(" "))
        .attr("x", x)
        .attr("y", Y)
        .attr("width", CELL_W - 12)
        .attr("height", CELL_H)
        .attr("rx", 18);

      svg
        .append("text")
        .attr("class", "fft-cell-index")
        .attr("x", x + (CELL_W - 12) / 2)
        .attr("y", Y + 20)
        .attr("text-anchor", "middle")
        .text(`slot ${index}`);

      svg
        .append("text")
        .attr("class", "fft-cell-value")
        .attr("x", x + (CELL_W - 12) / 2)
        .attr("y", Y + 48)
        .attr("text-anchor", "middle")
        .text(value);
    });
  }

  function renderSummary(root, state) {
    const stage = STAGES[state.stage];
    root.querySelector('[data-role="invariant"]').textContent =
      "A butterfly stage only mixes entries inside one local block. The correctness comes from the even/odd split and the twiddle factor for that block position.";
    root.querySelector('[data-role="stage"]').textContent = `${state.stage}/${STAGES.length - 1}: ${stage.title}`;
    root.querySelector('[data-role="details"]').innerHTML = stage.notes.map((line) => `<li>${line}</li>`).join("");
    root.querySelector('[data-role="formula"]').innerHTML = stage.formulas.map((line) => `<li><code>${line}</code></li>`).join("");
    root.querySelector('[data-role="note"]').textContent =
      state.stage < STAGES.length - 1
        ? "Use Next stage to see how one more layer of local butterflies rewrites the same polynomial information into a different coordinate system."
        : "At this point the array is in point-value form. Convolution becomes one entrywise multiplication here, and only later do you inverse-transform back.";
  }

  function rerender(root, state) {
    renderCanvas(root, state);
    renderSummary(root, state);
  }

  function next(state) {
    if (state.stage < STAGES.length - 1) {
      state.stage += 1;
    }
  }

  function prev(state) {
    if (state.stage > 0) {
      state.stage -= 1;
    }
  }

  function reset(state) {
    state.stage = 0;
  }

  function initOne(root) {
    if (root.dataset.initialized === "true") {
      return;
    }
    root.dataset.initialized = "true";

    const state = makeState();

    root.querySelector('[data-role="next"]').addEventListener("click", () => {
      next(state);
      rerender(root, state);
    });

    root.querySelector('[data-role="prev"]').addEventListener("click", () => {
      prev(state);
      rerender(root, state);
    });

    root.querySelector('[data-role="reset"]').addEventListener("click", () => {
      reset(state);
      rerender(root, state);
    });

    rerender(root, state);
  }

  function boot() {
    document.querySelectorAll("[data-fft-visualizer]").forEach(initOne);
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
