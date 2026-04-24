# Problem Finder

Use this page when you want one searchable view across both:

- repo notes in `problem-catalog.json`
- curated external practice in `external-problem-catalog.json`

You can filter by topic, difficulty, source, bucket, and content type without hopping between multiple index pages.

If you want the fastest way to narrow a practice set, start here first. Use the static indexes afterward when you want a full inventory view.

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
    </div>
    <div class="problem-finder-meta">
      <div id="finder-stats" class="problem-finder-stats"></div>
      <div class="finder-shortcuts">
        <a href="../problem-index/">Repo index</a>
        <a href="../external-problem-index/">External index</a>
        <a href="../topic-maps/">Topic maps</a>
      </div>
    </div>
  </div>

  <div class="problem-finder-results">
    <h2>Results</h2>
    <div id="finder-empty" class="finder-empty" hidden>No problems match the current filters.</div>
    <table class="problem-finder-table">
      <thead>
        <tr>
          <th>Problem</th>
          <th>Topic</th>
          <th>Kind</th>
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
