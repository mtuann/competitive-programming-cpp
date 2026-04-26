(() => {
  const SUPPORT_URL = "https://thanksalot.netlify.app/";

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

  function boot() {
    ensureSupportLink();
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
