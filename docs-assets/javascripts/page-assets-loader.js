(() => {
  const MATHJAX_URL = "https://unpkg.com/mathjax@3/es5/tex-mml-chtml.js";
  const D3_URL = "https://cdn.jsdelivr.net/npm/d3@7/dist/d3.min.js";
  const CYTOSCAPE_URL = "https://cdn.jsdelivr.net/npm/cytoscape@3/dist/cytoscape.min.js";
  const SUPPORT_URL = "https://thanksalot.netlify.app/";
  const currentScript = document.currentScript;
  const assetBase = currentScript ? new URL(".", currentScript.src).href : "/assets/javascripts/";

  const scriptCache = new Map();

  function loadScript(src) {
    if (scriptCache.has(src)) {
      return scriptCache.get(src);
    }

    const promise = new Promise((resolve, reject) => {
      const existing = document.querySelector(`script[src="${src}"]`);
      if (existing) {
        if (existing.dataset.loaded === "true") {
          resolve();
          return;
        }
        existing.addEventListener("load", () => resolve(), { once: true });
        existing.addEventListener("error", () => reject(new Error(`Failed to load ${src}`)), { once: true });
        return;
      }

      const script = document.createElement("script");
      script.src = src;
      script.async = true;
      script.addEventListener(
        "load",
        () => {
          script.dataset.loaded = "true";
          resolve();
        },
        { once: true },
      );
      script.addEventListener("error", () => reject(new Error(`Failed to load ${src}`)), { once: true });
      document.head.appendChild(script);
    });

    scriptCache.set(src, promise);
    return promise;
  }

  function loadLocalScript(filename) {
    return loadScript(new URL(filename, assetBase).href);
  }

  function ensureSupportLink() {
    const headerInner = document.querySelector(".md-header__inner");
    if (!headerInner || headerInner.querySelector(".cp-support-link")) {
      return;
    }

    const anchor = document.createElement("a");
    anchor.className = "cp-support-link";
    anchor.href = SUPPORT_URL;
    anchor.target = "_blank";
    anchor.rel = "noopener";
    anchor.title = "Support this project";
    anchor.setAttribute("aria-label", "Support this project");
    anchor.innerHTML = `
      <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
        <path d="M12.1 21.35l-1.1-1.02C5.14 14.91 2 12.05 2 8.5 2 5.91 3.99 4 6.5 4c1.74 0 3.41.81 4.5 2.09C12.09 4.81 13.76 4 15.5 4 18.01 4 20 5.91 20 8.5c0 3.55-3.14 6.41-8.99 11.83l-1.11 1.02h.2z"></path>
      </svg>
      <span>Support</span>
    `;

    const repoSource = headerInner.querySelector(".md-header__source");
    if (repoSource && repoSource.parentNode === headerInner) {
      headerInner.insertBefore(anchor, repoSource);
    } else {
      headerInner.appendChild(anchor);
    }
  }

  async function ensureMathJax() {
    if (!document.querySelector(".arithmatex")) {
      return;
    }

    await loadLocalScript("mathjax.js");

    if (!window.MathJax?.startup?.promise) {
      await loadScript(MATHJAX_URL);
    }
  }

  async function ensureD3() {
    if (window.d3) {
      return;
    }

    await loadScript(D3_URL);
  }

  async function ensureCytoscape() {
    if (window.cytoscape) {
      return;
    }

    await loadScript(CYTOSCAPE_URL);
  }

  async function ensureOptionalScript(selector, filename, dependencies = []) {
    if (!document.querySelector(selector)) {
      return;
    }
    await Promise.all(dependencies.map((dependency) => dependency()));
    await loadLocalScript(filename);
  }

  async function boot() {
    ensureSupportLink();

    const results = await Promise.allSettled([
      ensureMathJax(),
      ensureOptionalScript("#problem-finder-root", "problem-finder.js"),
      ensureOptionalScript("[data-bfs-dfs-visualizer]", "bfs-dfs-visualizer.js"),
      ensureOptionalScript("[data-fenwick-visualizer]", "fenwick-visualizer.js"),
      ensureOptionalScript("[data-segment-tree-visualizer]", "segment-tree-visualizer.js"),
      ensureOptionalScript("[data-binary-search-visualizer]", "binary-search-visualizer.js", [ensureD3]),
      ensureOptionalScript("[data-lazy-segment-tree-visualizer]", "lazy-segment-tree-visualizer.js", [ensureD3]),
      ensureOptionalScript("[data-euler-tour-visualizer]", "euler-tour-visualizer.js", [ensureD3]),
      ensureOptionalScript("[data-two-pointers-visualizer]", "two-pointers-visualizer.js", [ensureD3]),
      ensureOptionalScript("[data-digit-dp-visualizer]", "digit-dp-visualizer.js", [ensureD3]),
      ensureOptionalScript("[data-fft-visualizer]", "fft-visualizer.js", [ensureD3]),
      ensureOptionalScript("[data-lowlink-visualizer]", "lowlink-visualizer.js", [ensureCytoscape]),
      ensureOptionalScript("[data-aho-visualizer]", "aho-visualizer.js", [ensureCytoscape]),
      ensureOptionalScript("[data-max-flow-visualizer]", "max-flow-visualizer.js", [ensureCytoscape]),
      ensureOptionalScript("[data-sam-visualizer]", "sam-visualizer.js", [ensureCytoscape]),
    ]);

    results.forEach((result) => {
      if (result.status === "rejected") {
        console.error(result.reason);
      }
    });
  }

  if (typeof window.document$ !== "undefined" && typeof window.document$.subscribe === "function") {
    window.document$.subscribe(() => {
      void boot();
    });
  }

  if (document.readyState === "loading") {
    document.addEventListener(
      "DOMContentLoaded",
      () => {
        void boot();
      },
      { once: true },
    );
  } else {
    void boot();
  }
})();
