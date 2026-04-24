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
    area: document.getElementById("finder-area"),
    topic: document.getElementById("finder-topic"),
    difficulty: document.getElementById("finder-difficulty"),
    source: document.getElementById("finder-source"),
    bucket: document.getElementById("finder-bucket"),
  };

  const resultsBody = document.getElementById("finder-results");
  const emptyState = document.getElementById("finder-empty");
  const stats = document.getElementById("finder-stats");

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
      area: slugToArea(slug),
      slug,
      topic,
      title: row.title,
      difficulty: row.difficulty,
      source: row.judge,
      bucket: "",
      searchText: [
        row.title,
        row.full_title,
        row.main_topic,
        row.judge,
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
      area: slugToArea(slug),
      slug,
      topic: row.topic,
      title: row.title,
      difficulty: row.difficulty,
      source: row.source,
      bucket: row.bucket,
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
    stats.innerHTML = [
      `<span class="finder-chip">Showing <strong>${shownItems.length}</strong> of ${allItems.length}</span>`,
      `<span class="finder-chip">Repo notes ${repoCount}</span>`,
      `<span class="finder-chip">External ${externalCount}</span>`,
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
    renderRows(filtered);
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
      area: params.get("area") || "",
      topic: params.get("topic") || "",
      difficulty: params.get("difficulty") || "",
      source: params.get("source") || "",
      bucket: params.get("bucket") || "",
    };

    fillSelect(fields.kind, uniqueSorted(allItems.map((item) => item.kind)), initial.kind);
    fillSelect(fields.area, uniqueSorted(allItems.map((item) => item.area)), initial.area);
    fields.query.value = initial.query;
    fields.difficulty.value = initial.difficulty;
    fields.source.value = initial.source;
    fields.bucket.value = initial.bucket;

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
