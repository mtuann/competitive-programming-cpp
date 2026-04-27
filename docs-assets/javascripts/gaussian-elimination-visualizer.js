(() => {
  const MOD = 7;
  const WIDTH = 860;
  const HEIGHT = 320;
  const ROWS = ["R1", "R2"];
  const COLS = ["x", "y", "rhs"];
  const CELL_W = 112;
  const CELL_H = 62;
  const START_X = 212;
  const START_Y = 104;

  const STATES = [
    {
      title: "Stage 0 of 4",
      subtitle: "Choose a pivot row for column x",
      matrix: [
        [1, 1, 3],
        [2, 1, 4],
      ],
      activeCol: 0,
      pivots: [[0, 0]],
      activeRows: [0],
      changedCells: [],
      operation: "Pick R1 as the pivot row because its x-coefficient is nonzero.",
      where: "where[x] = R1, where[y] = -",
      status: "Column x is about to become the first pivot column.",
      formulas: [
        "No row operation yet: just choose a nonzero coefficient in the current column.",
        "Over a field, any nonzero pivot can later be normalized to 1.",
      ],
      note:
        "The invariant starts here: row operations may change the matrix shape, but they do not change the set of solutions to Ax = b.",
    },
    {
      title: "Stage 1 of 4",
      subtitle: "Eliminate x from the lower row",
      matrix: [
        [1, 1, 3],
        [0, 6, 5],
      ],
      activeCol: 0,
      pivots: [[0, 0]],
      activeRows: [1],
      changedCells: [
        [1, 0],
        [1, 1],
        [1, 2],
      ],
      operation: "Apply R2 <- R2 - 2 R1 (mod 7).",
      where: "where[x] = R1, where[y] = -",
      status: "Column x is now zero below the pivot.",
      formulas: [
        "R2: [2, 1 | 4] - 2 * [1, 1 | 3] = [0, -1 | -2] ≡ [0, 6 | 5] mod 7.",
        "The pivot column is now isolated downward.",
      ],
      note:
        "This is the first real elimination move: one pivot row controls the whole column, and every other row loses that variable there.",
    },
    {
      title: "Stage 2 of 4",
      subtitle: "Normalize the second pivot row",
      matrix: [
        [1, 1, 3],
        [0, 1, 2],
      ],
      activeCol: 1,
      pivots: [
        [0, 0],
        [1, 1],
      ],
      activeRows: [1],
      changedCells: [
        [1, 1],
        [1, 2],
      ],
      operation: "Apply R2 <- 6 R2 because 6^{-1} ≡ 6 (mod 7).",
      where: "where[x] = R1, where[y] = R2",
      status: "Column y now has a unit pivot in R2.",
      formulas: [
        "6^{-1} ≡ 6 mod 7 because 6 * 6 ≡ 1.",
        "6 * [0, 6 | 5] = [0, 1 | 2] mod 7.",
      ],
      note:
        "This is exactly why the repo's first route stays over a prime modulus: every nonzero pivot is invertible, so normalization is always legal.",
    },
    {
      title: "Stage 3 of 4",
      subtitle: "Eliminate y from the top row",
      matrix: [
        [1, 0, 1],
        [0, 1, 2],
      ],
      activeCol: 1,
      pivots: [
        [0, 0],
        [1, 1],
      ],
      activeRows: [0],
      changedCells: [
        [0, 1],
        [0, 2],
      ],
      operation: "Apply R1 <- R1 - R2 (mod 7).",
      where: "where[x] = R1, where[y] = R2",
      status: "Both pivot columns are now isolated everywhere else.",
      formulas: [
        "R1: [1, 1 | 3] - [0, 1 | 2] = [1, 0 | 1].",
        "The matrix is now in row-reduced form for this tiny system.",
      ],
      note:
        "After each pivot column becomes zero in every other row, the right-hand side is ready to be read as variable values.",
    },
    {
      title: "Stage 4 of 4",
      subtitle: "Read the unique solution",
      matrix: [
        [1, 0, 1],
        [0, 1, 2],
      ],
      activeCol: null,
      pivots: [
        [0, 0],
        [1, 1],
      ],
      activeRows: [],
      changedCells: [
        [0, 2],
        [1, 2],
      ],
      operation: "No more elimination is needed; read the answer from the augmented column.",
      where: "where[x] = R1, where[y] = R2",
      status: "Unique solution: x = 1, y = 2.",
      formulas: [
        "Pivot row R1 gives x = 1.",
        "Pivot row R2 gives y = 2.",
      ],
      note:
        "There is no all-zero left side with nonzero rhs, so the system is consistent. There are also no free columns, so the solution is unique.",
    },
  ];

  function key(row, col) {
    return `${row}-${col}`;
  }

  function makeState() {
    return { index: 0 };
  }

  function hasCell(cells, row, col) {
    return cells.some(([r, c]) => r === row && c === col);
  }

  function renderCanvas(root, state) {
    const host = root.querySelector('[data-role="canvas"]');
    host.innerHTML = "";

    const stage = STATES[state.index];
    const svg = d3
      .select(host)
      .append("svg")
      .attr("viewBox", `0 0 ${WIDTH} ${HEIGHT}`)
      .attr("class", "gauss-svg")
      .attr("role", "img")
      .attr("aria-label", "Gaussian elimination pivot and row-operation visualizer");

    svg
      .append("text")
      .attr("class", "gauss-stage-title")
      .attr("x", WIDTH / 2)
      .attr("y", 34)
      .attr("text-anchor", "middle")
      .text(stage.title);

    svg
      .append("text")
      .attr("class", "gauss-stage-subtitle")
      .attr("x", WIDTH / 2)
      .attr("y", 58)
      .attr("text-anchor", "middle")
      .text(stage.subtitle);

    if (stage.activeCol !== null) {
      const bandX = START_X + stage.activeCol * CELL_W - 10;
      svg
        .append("rect")
        .attr("class", "gauss-column-band")
        .attr("x", bandX)
        .attr("y", START_Y - 22)
        .attr("width", CELL_W)
        .attr("height", ROWS.length * CELL_H + 44)
        .attr("rx", 18);
    }

    COLS.forEach((label, col) => {
      svg
        .append("text")
        .attr("class", "gauss-col-label")
        .attr("x", START_X + col * CELL_W + (CELL_W - 16) / 2)
        .attr("y", START_Y - 20)
        .attr("text-anchor", "middle")
        .text(label);
    });

    ROWS.forEach((label, row) => {
      svg
        .append("text")
        .attr("class", "gauss-row-label")
        .attr("x", START_X - 34)
        .attr("y", START_Y + row * CELL_H + CELL_H / 2 + 6)
        .attr("text-anchor", "end")
        .text(label);
    });

    svg
      .append("line")
      .attr("class", "gauss-divider")
      .attr("x1", START_X + 2 * CELL_W - 12)
      .attr("x2", START_X + 2 * CELL_W - 12)
      .attr("y1", START_Y - 4)
      .attr("y2", START_Y + ROWS.length * CELL_H + 4);

    stage.matrix.forEach((rowValues, row) => {
      rowValues.forEach((value, col) => {
        const x = START_X + col * CELL_W;
        const y = START_Y + row * CELL_H;
        const classes = ["gauss-cell"];
        if (col === 2) {
          classes.push("is-rhs");
        }
        if (stage.activeRows.includes(row)) {
          classes.push("is-active-row");
        }
        if (hasCell(stage.changedCells, row, col)) {
          classes.push("is-changed");
        }
        if (hasCell(stage.pivots, row, col)) {
          classes.push("is-pivot");
        }

        svg
          .append("rect")
          .attr("class", classes.join(" "))
          .attr("x", x)
          .attr("y", y)
          .attr("width", CELL_W - 16)
          .attr("height", CELL_H - 10)
          .attr("rx", 16);

        svg
          .append("text")
          .attr("class", "gauss-cell-value")
          .attr("x", x + (CELL_W - 16) / 2)
          .attr("y", y + 34)
          .attr("text-anchor", "middle")
          .text(value);
      });
    });
  }

  function renderSummary(root, state) {
    const stage = STATES[state.index];
    root.querySelector('[data-role="invariant"]').textContent =
      "One column at a time: choose a nonzero pivot, normalize it if needed, and clear that column from every other row without changing the solution set.";
    root.querySelector('[data-role="stage"]').textContent = `${stage.title} | ${stage.subtitle}`;
    root.querySelector('[data-role="operation"]').textContent = stage.operation;
    root.querySelector('[data-role="where"]').textContent = stage.where;
    root.querySelector('[data-role="status"]').textContent = stage.status;
    root.querySelector('[data-role="formulas"]').innerHTML = stage.formulas.map((line) => `<li><code>${line}</code></li>`).join("");
    root.querySelector('[data-role="note"]').textContent = stage.note;
  }

  function rerender(root, state) {
    renderCanvas(root, state);
    renderSummary(root, state);
  }

  function next(state) {
    if (state.index < STATES.length - 1) {
      state.index += 1;
    }
  }

  function prev(state) {
    if (state.index > 0) {
      state.index -= 1;
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
    document.querySelectorAll("[data-gaussian-visualizer]").forEach(initOne);
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
