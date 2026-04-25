# Problem Finder

Use this page when you want one searchable view across both:

- repo notes in `problem-catalog.json`
- curated external practice in `external-problem-catalog.json`

You can filter by topic, difficulty, source, bucket, and content type without hopping between multiple index pages.

If you want the fastest way to narrow a practice set, start here first. Use the static indexes afterward when you want a full inventory view.

This page is best when you treat it like a practice control panel, not just a search box:

- `Status` is the repo-note training log: `todo`, `attempted`, `solved`, `reviewed`
- `Kind` splits internal notes from fresh external follow-up
- session presets are meant to answer `what do I do right now?`, not only `what exists?`
- `Session size` turns a long filtered list into one concrete queue for the current block
- `Queue board` tells you whether you should resume, review, or leave the repo for fresh reps

## Best Use Cases

Use this page when:

- you know the weak topic but not the next good problem
- you want to build a short ladder for one subtopic
- a mixed round or contest exposed a weak slot and you want the next follow-up set quickly
- you want to resume attempted notes or build a light review queue without scanning the whole repo

Do **not** stay here forever. After you narrow the list, jump into a real workflow.

## After You Narrow The List

| If you found... | Go next |
| --- | --- |
| one weak subtopic | [Practice hub](../practice/README.md) or the corresponding ladder |
| one weak contest skill | [Contest Playbooks](../practice/contest-playbooks/README.md) |
| one weak retrieval family | [Notebook](../notebook/README.md) |
| one weak implementation family | [Build Kit](build-kit.md) |

## Status Discipline

Use repo-note statuses consistently so this page becomes a real training system:

- `todo`: selected, but not honestly attempted yet
- `attempted`: you tried it and want a clean return path
- `solved`: you finished it once, but it is still live material for review
- `reviewed`: you reopened it deliberately and no longer need it in the first review queue

External problems do not use repo-note status. Treat them as fresh follow-up reps after the topic is already mostly trusted.

<div id="problem-finder-root" class="problem-finder-shell">
  <div class="problem-finder-toolbar">
    <h2>Filter The Catalog</h2>
    <div class="problem-finder-grid">
      <div class="problem-finder-field">
        <label for="finder-query">Search</label>
        <input id="finder-query" type="search" placeholder="title, topic, tag, pattern, source" />
      </div>
      <div class="problem-finder-field">
        <label for="finder-kind">Kind</label>
        <select id="finder-kind">
          <option value="">All</option>
        </select>
      </div>
      <div class="problem-finder-field">
        <label for="finder-status">Status</label>
        <select id="finder-status">
          <option value="">All</option>
        </select>
      </div>
      <div class="problem-finder-field">
        <label for="finder-area">Area</label>
        <select id="finder-area">
          <option value="">All</option>
        </select>
      </div>
      <div class="problem-finder-field">
        <label for="finder-topic">Topic</label>
        <select id="finder-topic">
          <option value="">All</option>
        </select>
      </div>
      <div class="problem-finder-field">
        <label for="finder-difficulty">Difficulty</label>
        <select id="finder-difficulty">
          <option value="">All</option>
        </select>
      </div>
      <div class="problem-finder-field">
        <label for="finder-source">Source</label>
        <select id="finder-source">
          <option value="">All</option>
        </select>
      </div>
      <div class="problem-finder-field">
        <label for="finder-bucket">Bucket</label>
        <select id="finder-bucket">
          <option value="">All</option>
        </select>
      </div>
      <div class="problem-finder-field">
        <label for="finder-limit">Session size</label>
        <select id="finder-limit">
          <option value="3">3 picks</option>
          <option value="5">5 picks</option>
          <option value="10">10 picks</option>
          <option value="all">Show all</option>
        </select>
      </div>
      <div class="problem-finder-field">
        <label for="finder-sort">Sort</label>
        <select id="finder-sort">
          <option value="queue">Queue order</option>
          <option value="difficulty">Difficulty</option>
          <option value="topic">Topic</option>
          <option value="source">Source</option>
        </select>
      </div>
    </div>
    <div class="problem-finder-meta">
      <div id="finder-stats" class="problem-finder-stats"></div>
      <div class="finder-shortcuts">
        <a href="../../practice/">Practice hub</a>
        <a href="../../practice/mixed-rounds/">Mixed rounds</a>
        <a href="../../practice/contest-playbooks/">Contest playbooks</a>
        <a href="../../notebook/">Notebook</a>
        <a href="../build-kit/">Build Kit</a>
        <a href="../../template-library/">Template library</a>
        <a href="../problem-index/">Repo index</a>
        <a href="../external-problem-index/">External index</a>
        <a href="../topic-maps/">Topic maps</a>
      </div>
    </div>
  </div>

  <div class="problem-finder-presets">
    <h2>Session Presets</h2>
    <p class="finder-helper">
      These presets are meant to answer common training questions fast. Use them first, then narrow by topic or difficulty.
    </p>
    <div class="finder-preset-row">
      <button type="button" class="finder-preset" data-finder-preset="resume-attempted">Resume attempted</button>
      <button type="button" class="finder-preset" data-finder-preset="review-solved">Review solved</button>
      <button type="button" class="finder-preset" data-finder-preset="reopen-reviewed">Reopen reviewed</button>
      <button type="button" class="finder-preset" data-finder-preset="fresh-external">Fresh external reps</button>
      <button type="button" class="finder-preset" data-finder-preset="core-external">Core external set</button>
      <button type="button" class="finder-preset" data-finder-preset="challenge-push">Challenge push</button>
      <button type="button" class="finder-preset finder-preset--ghost" data-finder-reset>Clear filters</button>
    </div>
  </div>

  <div id="finder-queue-board" class="problem-finder-queue-board"></div>
  <div id="finder-route" class="problem-finder-route" hidden></div>
  <div id="finder-session" class="problem-finder-session" hidden></div>

  <div class="problem-finder-results">
    <h2>Results</h2>
    <div id="finder-empty" class="finder-empty" hidden>No problems match the current filters.</div>
    <table class="problem-finder-table">
      <thead>
        <tr>
          <th>Problem</th>
          <th>Topic</th>
          <th>Kind</th>
          <th>Status</th>
          <th>Difficulty</th>
          <th>Source</th>
          <th>Bucket</th>
          <th>Links</th>
        </tr>
      </thead>
      <tbody id="finder-results"></tbody>
    </table>
  </div>
</div>
