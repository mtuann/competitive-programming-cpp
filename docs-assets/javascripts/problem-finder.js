(function () {
  const root = document.getElementById("problem-finder-root");
  if (!root) {
    return;
  }

  const basePrefix = "../../";
  const repoCatalogUrl = `${basePrefix}data/problem-catalog.json`;
  const externalCatalogUrl = `${basePrefix}data/external-problem-catalog.json`;

  const fields = {
    query: document.getElementById("finder-query"),
    kind: document.getElementById("finder-kind"),
    status: document.getElementById("finder-status"),
    area: document.getElementById("finder-area"),
    topic: document.getElementById("finder-topic"),
    difficulty: document.getElementById("finder-difficulty"),
    source: document.getElementById("finder-source"),
    bucket: document.getElementById("finder-bucket"),
  };

  const resultsBody = document.getElementById("finder-results");
  const emptyState = document.getElementById("finder-empty");
  const stats = document.getElementById("finder-stats");
  const routeCard = document.getElementById("finder-route");
  const presetButtons = Array.from(root.querySelectorAll("[data-finder-preset]"));
  const resetButton = root.querySelector("[data-finder-reset]");
  const STATUS_VALUES = ["todo", "attempted", "solved", "reviewed"];

  function docHref(path) {
    if (!path) {
      return "";
    }
    return (
      basePrefix +
      path
        .replace(/README\.md$/, "")
        .replace(/\.md$/, "/")
        .replace(/^\/+/, "")
    );
  }

  function textOf(value) {
    return (value || "").toString().trim();
  }

  function labelOf(value) {
    return textOf(value) || "-";
  }

  function makeLink(href, label) {
    if (!href) {
      return "";
    }
    return `<a href="${href}">${label}</a>`;
  }

  function slugToArea(slug) {
    return textOf(slug).split("/")[0] || "";
  }

  function uniqueSorted(values) {
    return Array.from(new Set(values.filter(Boolean))).sort((a, b) =>
      a.localeCompare(b, undefined, { sensitivity: "base" })
    );
  }

  function normalizeRepoItem(row) {
    const slug = row.primary_slug;
    const topic = row.main_topic || slug;
    return {
      kind: "Repo note",
      status: row.status || "",
      area: slugToArea(slug),
      slug,
      topic,
      title: row.title,
      difficulty: row.difficulty,
      source: row.judge,
      bucket: "",
      notePath: row.note_path,
      ladderPath: row.ladder_path,
      tutorialPath: row.tutorial_path,
      mapPath: `docs/topic-maps/${slug}.md`,
      judgeUrl: row.judge_url,
      solutionUrl: row.solution_url,
      searchText: [
        row.title,
        row.full_title,
        row.main_topic,
        row.judge,
        row.status,
        ...(row.secondary_topics || []),
        ...(row.patterns || []),
        ...(row.tracks || []),
      ]
        .filter(Boolean)
        .join(" ")
        .toLowerCase(),
      links: [
        makeLink(docHref(row.note_path), "Note"),
        makeLink(docHref(`docs/topic-maps/${slug}.md`), "Map"),
        makeLink(docHref(row.tutorial_path), "Tutorial"),
        makeLink(docHref(row.ladder_path), "Ladder"),
        makeLink(row.judge_url, "Judge"),
        makeLink(row.solution_url, "Code"),
      ].filter(Boolean),
    };
  }

  function normalizeExternalItem(row) {
    const slug = row.slug;
    return {
      kind: "External",
      status: "",
      area: slugToArea(slug),
      slug,
      topic: row.topic,
      title: row.title,
      difficulty: row.difficulty,
      source: row.source,
      bucket: row.bucket,
      mapPath: `docs/topic-maps/${slug}.md`,
      problemUrl: row.url,
      searchText: [
        row.title,
        row.topic,
        row.source,
        ...(row.tracks || []),
        ...(row.tags || []),
        ...(row.styles || []),
        ...(row.prerequisites || []),
        row.why_fit,
      ]
        .filter(Boolean)
        .join(" ")
        .toLowerCase(),
      links: [
        makeLink(row.url, "Problem"),
        makeLink(docHref(`docs/topic-maps/${slug}.md`), "Map"),
      ].filter(Boolean),
    };
  }

  function fillSelect(select, values, currentValue) {
    const firstOption = select.querySelector('option[value=""]');
    select.innerHTML = "";
    select.appendChild(firstOption || new Option("All", ""));
    values.forEach((value) => {
      const option = new Option(value, value);
      if (value === currentValue) {
        option.selected = true;
      }
      select.appendChild(option);
    });
  }

  function currentState() {
    return {
      query: fields.query.value.trim().toLowerCase(),
      kind: fields.kind.value,
      status: fields.status.value,
      area: fields.area.value,
      topic: fields.topic.value,
      difficulty: fields.difficulty.value,
      source: fields.source.value,
      bucket: fields.bucket.value,
    };
  }

  function updateUrl(state) {
    const params = new URLSearchParams();
    Object.entries(state).forEach(([key, value]) => {
      if (value) {
        params.set(key, value);
      }
    });
    const query = params.toString();
    const nextUrl = `${window.location.pathname}${query ? `?${query}` : ""}`;
    window.history.replaceState({}, "", nextUrl);
  }

  function renderStats(allItems, shownItems) {
    const repoCount = shownItems.filter((item) => item.kind === "Repo note").length;
    const externalCount = shownItems.length - repoCount;
    const statusCounts = STATUS_VALUES.map((status) => ({
      status,
      count: shownItems.filter((item) => item.kind === "Repo note" && item.status === status).length,
    })).filter((entry) => entry.count > 0);
    stats.innerHTML = [
      `<span class="finder-chip">Showing <strong>${shownItems.length}</strong> of ${allItems.length}</span>`,
      `<span class="finder-chip">Repo notes ${repoCount}</span>`,
      `<span class="finder-chip">External ${externalCount}</span>`,
      ...statusCounts.map(
        (entry) =>
          `<span class="finder-chip">Status ${entry.status} ${entry.count}</span>`
      ),
    ].join("");
  }

  function renderRows(items) {
    resultsBody.innerHTML = "";
    if (!items.length) {
      emptyState.hidden = false;
      return;
    }
    emptyState.hidden = true;

    items.forEach((item) => {
      const row = document.createElement("tr");
      const cells = [
        ["Problem", `<strong>${item.title}</strong>`],
        ["Topic", labelOf(item.topic)],
        ["Kind", `<code>${item.kind}</code>`],
        ["Status", `<code>${labelOf(item.status)}</code>`],
        ["Difficulty", `<code>${labelOf(item.difficulty)}</code>`],
        ["Source", `<code>${labelOf(item.source)}</code>`],
        ["Bucket", `<code>${labelOf(item.bucket)}</code>`],
        ["Links", `<div class="finder-links">${item.links.join("")}</div>`],
      ];
      row.innerHTML = cells
        .map(([label, content]) => `<td data-label="${label}">${content}</td>`)
        .join("");
      resultsBody.appendChild(row);
    });
  }

  function applyFilters(allItems) {
    const state = currentState();
    const filtered = allItems.filter((item) => {
      if (state.kind && item.kind !== state.kind) return false;
      if (state.status && item.status !== state.status) return false;
      if (state.area && item.area !== state.area) return false;
      if (state.topic && item.topic !== state.topic) return false;
      if (state.difficulty && item.difficulty !== state.difficulty) return false;
      if (state.source && item.source !== state.source) return false;
      if (state.bucket && item.bucket !== state.bucket) return false;
      if (state.query && !item.searchText.includes(state.query)) return false;
      return true;
    });

    filtered.sort((a, b) => {
      return (
        a.area.localeCompare(b.area) ||
        a.topic.localeCompare(b.topic) ||
        a.kind.localeCompare(b.kind) ||
        a.title.localeCompare(b.title)
      );
    });

    updateUrl(state);
    renderStats(allItems, filtered);
    renderRoute(state, filtered);
    updatePresetSelection(state);
    renderRows(filtered);
  }

  function setState(nextState, allItems) {
    fields.query.value = nextState.query || "";
    fields.kind.value = nextState.kind || "";
    fields.status.value = nextState.status || "";
    fields.area.value = nextState.area || "";
    syncTopicOptions(allItems);
    fields.topic.value = nextState.topic || "";
    fields.difficulty.value = nextState.difficulty || "";
    fields.source.value = nextState.source || "";
    fields.bucket.value = nextState.bucket || "";
    applyFilters(allItems);
  }

  function routeShortcut(href, label) {
    return href ? `<a href="${href}">${label}</a>` : "";
  }

  function finderRoute(title, body, links) {
    const renderedLinks = links.filter(Boolean).join("");
    routeCard.hidden = false;
    routeCard.innerHTML = `
      <h2>${title}</h2>
      <p class="finder-helper">${body}</p>
      <div class="finder-shortcuts">${renderedLinks}</div>
    `;
  }

  function renderRoute(state, items) {
    const firstRepo = items.find((item) => item.kind === "Repo note");
    const firstExternal = items.find((item) => item.kind === "External");

    if (state.status === "todo") {
      if (!firstRepo) {
        finderRoute(
          "Start Queue",
          "No repo notes currently match this queue. Mark note frontmatter statuses honestly so `todo` becomes the place where chosen problems wait before the first real attempt.",
          [
            routeShortcut(docHref("practice/README.md"), "Practice hub"),
            routeShortcut(docHref("docs/authoring/problem-note-contract.md"), "Status contract"),
            routeShortcut(docHref("topics/README.md"), "Topics hub"),
          ]
        );
        return;
      }

      finderRoute(
        "Start Queue",
        "These notes were selected but not honestly attempted yet. Reopen the topic only if the family is still shaky, then make the first real attempt before reaching for Build Kit.",
        [
          routeShortcut(docHref(firstRepo.notePath), "Open first note"),
          routeShortcut(docHref(firstRepo.tutorialPath), "Reopen topic"),
          routeShortcut(docHref(firstRepo.ladderPath), "Stay in ladder"),
          routeShortcut(docHref("notebook/README.md"), "Notebook"),
        ]
      );
      return;
    }

    if (state.status === "attempted") {
      if (!firstRepo) {
        finderRoute(
          "Resume Queue",
          "No repo notes currently match this queue. Mark note frontmatter statuses honestly so `attempted` becomes a real restart path instead of a memory game.",
          [
            routeShortcut(docHref("practice/README.md"), "Practice hub"),
            routeShortcut(docHref("docs/authoring/problem-note-contract.md"), "Status contract"),
            routeShortcut(docHref("notebook/README.md"), "Notebook"),
          ]
        );
        return;
      }

      finderRoute(
        "Resume Queue",
        "Resume one note cleanly: reopen the topic only if recognition is fuzzy, then use Build Kit or Notebook only after one more honest attempt.",
        [
          routeShortcut(docHref(firstRepo.notePath), "Open first note"),
          routeShortcut(docHref(firstRepo.tutorialPath), "Reopen topic"),
          routeShortcut(docHref(firstRepo.ladderPath), "Stay in ladder"),
          routeShortcut(docHref("docs/build-kit.md"), "Build Kit"),
          routeShortcut(docHref("notebook/README.md"), "Notebook"),
        ]
      );
      return;
    }

    if (state.status === "solved" || state.status === "reviewed") {
      finderRoute(
        state.status === "solved" ? "Review Queue" : "Mature Anchor Queue",
        state.status === "solved"
          ? "Use solved notes for deliberate review, not passive rereading. Narrow by topic or difficulty, then jump to a mixed round or one fresh follow-up problem."
          : "These are already reviewed anchors. Reopen them only when you want a stable compare point, then leave quickly for fresh reps.",
        [
          routeShortcut(firstRepo ? docHref(firstRepo.notePath) : "", "Open first note"),
          routeShortcut(docHref("practice/mixed-rounds/README.md"), "Mixed Rounds"),
          routeShortcut(docHref("practice/contest-playbooks/README.md"), "Contest Playbooks"),
          routeShortcut(docHref("docs/external-problem-index.md"), "External follow-up"),
        ]
      );
      return;
    }

    if (state.kind === "External") {
      finderRoute(
        "Fresh External Follow-Up",
        "Use external problems after the topic is already mostly trusted. Reopen the topic map if needed, solve one fresh rep, then come back only if recognition or implementation still drifts.",
        [
          routeShortcut(firstExternal ? docHref(firstExternal.mapPath) : "", "Open topic map"),
          routeShortcut(docHref("topics/README.md"), "Topics hub"),
          routeShortcut(firstExternal ? firstExternal.problemUrl : "", "Open first problem"),
        ]
      );
      return;
    }

    if (state.topic || state.area) {
      if (!firstRepo && firstExternal) {
        finderRoute(
          "Weak Subtopic Replay",
          "This slice currently opens more naturally through external follow-up than through a repo note. Reopen the map or topic first, then use one fresh rep as the first concrete checkpoint.",
          [
            routeShortcut(docHref(firstExternal.mapPath), "Open topic map"),
            routeShortcut(docHref("topics/README.md"), "Topics hub"),
            routeShortcut(firstExternal.problemUrl, "Open first problem"),
          ]
        );
        return;
      }

      finderRoute(
        "Weak Subtopic Replay",
        "You already narrowed the family. Stay inside one topic long enough to recover recognition, then branch to fresh external follow-up only after the repo note route feels stable again.",
        [
          routeShortcut(firstRepo ? docHref(firstRepo.ladderPath) : "", "Open ladder"),
          routeShortcut(firstRepo ? docHref(firstRepo.tutorialPath) : "", "Open tutorial"),
          routeShortcut(firstRepo ? docHref(firstRepo.notePath) : "", "Open first note"),
          routeShortcut(docHref("notebook/README.md"), "Notebook"),
        ]
      );
      return;
    }

    finderRoute(
      "Choose A Session First",
      "Pick a preset when the question is operational: resume, review, or get a fresh external follow-up set. Use manual filters only after you know which practice mode you are in.",
      [
        routeShortcut(docHref("practice/README.md"), "Practice hub"),
        routeShortcut(docHref("practice/mixed-rounds/README.md"), "Mixed Rounds"),
        routeShortcut(docHref("practice/contest-playbooks/README.md"), "Contest Playbooks"),
      ]
    );
  }

  function presetState(name) {
    const base = {
      query: "",
      kind: "",
      status: "",
      area: "",
      topic: "",
      difficulty: "",
      source: "",
      bucket: "",
    };

    if (name === "resume-attempted") {
      return { ...base, kind: "Repo note", status: "attempted" };
    }
    if (name === "review-solved") {
      return { ...base, kind: "Repo note", status: "solved" };
    }
    if (name === "reopen-reviewed") {
      return { ...base, kind: "Repo note", status: "reviewed" };
    }
    if (name === "fresh-external") {
      return { ...base, kind: "External" };
    }
    if (name === "core-external") {
      return { ...base, kind: "External", bucket: "core" };
    }
    if (name === "challenge-push") {
      return { ...base, kind: "External", bucket: "challenge" };
    }
    return base;
  }

  function stateMatchesPreset(state, presetName) {
    const preset = presetState(presetName);
    return Object.keys(preset).every((key) => {
      if (!preset[key]) {
        return true;
      }
      return (state[key] || "") === preset[key];
    });
  }

  function updatePresetSelection(state) {
    let bestPreset = "";
    let bestScore = -1;

    presetButtons.forEach((button) => {
      const presetName = button.dataset.finderPreset;
      if (!stateMatchesPreset(state, presetName)) {
        return;
      }

      const preset = presetState(presetName);
      const score = Object.values(preset).filter(Boolean).length;
      if (score > bestScore) {
        bestScore = score;
        bestPreset = presetName;
      }
    });

    presetButtons.forEach((button) => {
      button.classList.toggle("finder-preset--active", button.dataset.finderPreset === bestPreset);
    });
  }

  function syncTopicOptions(allItems) {
    const selectedArea = fields.area.value;
    const selectedTopic = fields.topic.value;
    const topicValues = uniqueSorted(
      allItems
        .filter((item) => !selectedArea || item.area === selectedArea)
        .map((item) => item.topic)
    );
    fillSelect(fields.topic, topicValues, topicValues.includes(selectedTopic) ? selectedTopic : "");
  }

  function initializeFilters(allItems) {
    const params = new URLSearchParams(window.location.search);
    const initial = {
      query: params.get("query") || "",
      kind: params.get("kind") || "",
      status: params.get("status") || "",
      area: params.get("area") || "",
      topic: params.get("topic") || "",
      difficulty: params.get("difficulty") || "",
      source: params.get("source") || "",
      bucket: params.get("bucket") || "",
    };

    fillSelect(fields.kind, uniqueSorted(allItems.map((item) => item.kind)), initial.kind);
    fillSelect(fields.status, STATUS_VALUES, initial.status);
    fillSelect(fields.area, uniqueSorted(allItems.map((item) => item.area)), initial.area);
    fields.query.value = initial.query;

    fillSelect(fields.difficulty, uniqueSorted(allItems.map((item) => item.difficulty)), initial.difficulty);
    fillSelect(fields.source, uniqueSorted(allItems.map((item) => item.source)), initial.source);
    fillSelect(fields.bucket, uniqueSorted(allItems.map((item) => item.bucket)), initial.bucket);
    syncTopicOptions(allItems);
    fields.topic.value = initial.topic;

    Object.values(fields).forEach((field) => {
      field.addEventListener("input", () => {
        if (field === fields.area) {
          syncTopicOptions(allItems);
        }
        applyFilters(allItems);
      });
      field.addEventListener("change", () => {
        if (field === fields.area) {
          syncTopicOptions(allItems);
        }
        applyFilters(allItems);
      });
    });

    presetButtons.forEach((button) => {
      button.addEventListener("click", () => {
        setState(presetState(button.dataset.finderPreset), allItems);
      });
    });

    if (resetButton) {
      resetButton.addEventListener("click", () => {
        setState(presetState(""), allItems);
      });
    }

    applyFilters(allItems);
  }

  Promise.all([
    fetch(repoCatalogUrl).then((response) => response.json()),
    fetch(externalCatalogUrl).then((response) => response.json()),
  ])
    .then(([repoRows, externalRows]) => {
      const items = [
        ...repoRows.map(normalizeRepoItem),
        ...externalRows.map(normalizeExternalItem),
      ];
      initializeFilters(items);
    })
    .catch((error) => {
      emptyState.hidden = false;
      emptyState.textContent = `Problem Finder could not load the catalog data: ${error}`;
    });
})();
