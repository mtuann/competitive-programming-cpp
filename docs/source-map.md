# Curriculum Source Map

Research snapshot: `April 22, 2026`

Freshness-sensitive link and wording review: `April 24, 2026`

This repository design is grounded in public official or project-primary sources. The phrase "all top CS universities" is not literally enumerable in one pass, so this source map uses a representative set of leading public syllabi and public contest systems rather than pretending every school in the world exposes the same level of detail.

## How To Read This File

- `official` means a university course page, catalog, contest site, syllabus, or project homepage
- `project-primary` means the maintained homepage or repository of a widely used resource
- learner-facing topic maps normalize raw source labels into the repo taxonomy: `Primary`, `Course`, `Reference`, `Essay / Blog`, and `Practice`
- terms are written exactly when possible, such as `Fall 2025` or `Spring 2026`
- when a contest has no single official syllabus, the curriculum role is inferred from official rules, archives, curriculum pages, and training materials
- this file is the repo-level research snapshot, but freshness-sensitive pages should still record their own review context when current behavior or recommendations matter

## 1. Foundational University Syllabi

These sources shaped the beginner-to-intermediate curriculum.

| School | Official source and term | Why it matters for this repo | Link |
| --- | --- | --- | --- |
| `MIT` | `6.1210 Introduction to Algorithms`, `Fall 2025` archive, plus `Spring 2026` theory calendar | Clear statement of modeling computational problems, core paradigms, and the relation between algorithms and programming | [MIT catalog archive](https://student.mit.edu/catalog/archive/fall/m6a.html), [MIT theory calendar](https://toc.csail.mit.edu/courses) |
| `Stanford` | `CS161`, `Fall 2025` | Excellent modern undergrad baseline: recurrences, sorting, trees, randomized algorithms, graph algorithms, DP, greedy, and max-flow | [CS161 home](https://cs161-stanford.github.io), [CS161 schedule](https://cs161-stanford.github.io/schedule/) |
| `Berkeley` | `CS 170 Efficient Algorithms and Intractable Problems`, `Spring 2026` / `Fall 2026` listing | Strong bridge from algorithms to theory: design and analysis, models of computation, lower bounds, algebraic and combinatorial algorithms, NP-completeness | [CS 170 course page](https://www2.eecs.berkeley.edu/Courses/CS170/index.html) |
| `CMU` | `15-451/651 Algorithm Design and Analysis`, `Fall 2025` | A compact but very strong "serious algorithms" course spanning DP, graphs, network flows, LP, approximation, online, streaming, and probabilistic analysis | [15-451/651 Fall 2025](https://www.cs.cmu.edu/~15451-f25/) |
| `Princeton` | `COS 226 Algorithms and Data Structures`, `Spring 2026` | Useful because it stays implementation-heavy while still covering late-term DP, max-flow, multiplicative weights, randomness, and intractability | [COS 226 syllabus](https://www.cs.princeton.edu/~cos226), [COS 226 lectures](https://www.cs.princeton.edu/courses/archive/spring26/cos226/lectures.php) |
| `Cornell` | `CS 4820 Introduction to Analysis of Algorithms`, `Spring 2025` | Especially valuable for a repo that wants theory plus practice: greedy, DP, network flow, FFT, NP-hardness, approximation, computability, and even cryptography | [CS 4820 syllabus](https://www.cs.cornell.edu/courses/cs4820/2025sp/syllabus/), [CS 4820 lectures](https://www.cs.cornell.edu/courses/cs4820/2025sp/lectures/) |
| `UIUC` | `CS 473 Algorithms`, `Spring 2026` | Good reference for advanced-undergrad expectations and postrequisite branching into randomized algorithms, complexity, and approximation | [CS 473 Spring 2026](https://courses.grainger.illinois.edu/cs473/) |
| `Oxford` | `Design and Analysis of Algorithms`, `2025-2026` | Public non-US reference reinforcing data structures, algorithm design, worst-case analysis, and practical application | [Oxford course page](https://www.cs.ox.ac.uk/teaching/courses/2025-2026/algdesign/) |

### What repeated most across these syllabi

- `graphs`
- `dynamic programming`
- `greedy algorithms`
- `proof and analysis tools`
- `data structures`
- `shortest paths`, `MST`, and related combinatorial core

That repetition is why the README centers those topics early instead of treating them as one category among many.

## 2. Advanced Theory and Specialized Algorithms

These sources shaped the upper stages of the roadmap.

| Source | Term | Main contribution | Link |
| --- | --- | --- | --- |
| `MIT 6.1220J Design and Analysis of Algorithms` | `Fall 2025` archive and `Spring 2026` active listing | Core rigorous theory layer after intro algorithms: sorting, search trees, heaps, hashing, divide and conquer, DP, greedy, graph algorithms, shortest paths, and advanced topics like geometry, number theory, matrix methods, caching, and parallelism | [MIT catalog archive](https://student.mit.edu/catalog/archive/fall/m6a.html), [MIT theory calendar](https://toc.csail.mit.edu/courses) |
| `MIT 6.5220/6.856J Randomized Algorithms` | `Spring 2025` course site and `Fall 2025` catalog description | Random sampling, witnesses, symmetry breaking, Markov chains, min-cuts, approximate counting, online and parallel algorithms, derandomization | [course site](https://courses.csail.mit.edu/6.856/current/), [catalog listing](https://toc.csail.mit.edu/node/1740) |
| `MIT 6.5060 Algorithm Engineering` | `Fall 2025` | Sequential, parallel, cache-efficient, and external-memory algorithms, with graph problems and performance engineering | [MIT subject update](https://www.eecs.mit.edu/academics/subject-updates/subjects-update-fall-2025/), [MIT theory page](https://toc.csail.mit.edu/node/1739) |
| `MIT 6.1400J Computability and Complexity Theory` | `Fall 2025` archive | Formal models of computation, P vs NP, randomness, communication complexity, and hardness language for the theory tier | [MIT catalog archive](https://student.mit.edu/catalog/archive/fall/m6a.html) |
| `Berkeley CS174 Combinatorics and Discrete Probability` | `Spring 2025` | Randomized routing, min-cut, Chernoff/Hoeffding bounds, probabilistic method, Markov chains, approximate counting, martingales, primality testing, fingerprinting | [CS174 Spring 2025](https://people.eecs.berkeley.edu/~sinclair/cs174/s25.html) |
| `Princeton COS 521 Advanced Algorithm Design` | `Fall 2025` | Randomized min-cut, concentration, hashing, streaming, dimension reduction, LP and SDP, submodularity, online algorithms, parameterized complexity, graph sparsification, external memory | [COS 521 Fall 2025](https://www.cs.princeton.edu/~hy2/teaching/fall25-cos521/index.html), [info sheet](https://www.cs.princeton.edu/~hy2/teaching/fall25-cos521/infosheet.pdf) |
| `Cornell CS 5820/6820` | `Fall 2025` | Matchings, flows, LP and SDP, convex optimization, approximation, submodular optimization, spectral methods, Markov chains | [CS 6820 syllabus](https://www.cs.cornell.edu/courses/cs6820/2025fa/syllabus.html), [CS 6820 lectures](https://www.cs.cornell.edu/courses/cs6820/2025fa/lectures.html) |

### Design consequence

The advanced half of this repository should not stop at "harder graph tricks." Public advanced syllabi repeatedly emphasize:

- `randomized algorithms`
- `optimization`
- `approximation`
- `spectral / convex / LP ideas`
- `complexity`
- `algorithm engineering`

That is why the README includes a dedicated `Stage 5` instead of treating all advanced material as one bag of templates.

## 3. Official Contest Systems

These sources shaped the contest-facing parts of the repository.

| Contest or system | Primary official source | What it contributes to the design | Link |
| --- | --- | --- | --- |
| `IOI` | `IOI 2025 official syllabus` and official syllabus page | The clearest official syllabus in the space: included, out-of-focus, and excluded topics; strong guidance for what an olympiad-aligned curriculum should and should not frontload | [IOI syllabus page](https://ioinformatics.org/page/syllabus), [IOI 2025 PDF](https://ioinformatics.org/files/ioi-syllabus-2025.pdf) |
| `ICPC` | `ICPC Curriculum Committee`, `ICPC U`, `Problem Archive`, and `NAPC` | No single official syllabus, but a strong official curriculum ecosystem for breadth, teamwork, notebook habits, and training structure | [ICPC curriculum about](https://curriculum.u.icpc.global/about/), [ICPC curriculum topics](https://curriculum.u.icpc.global/curriculum/), [ICPC U](https://u.icpc.global/), [Problem Archive](https://foundation.icpc.global/archive/), [NAPC](https://nac.icpc.global/napc/) |
| `USACO` | `USACO details/FAQ` and official training system | Official staged progression from Bronze to Platinum, plus training and camp pipeline; excellent for designing ladders even though it does not publish one universal syllabus document | [USACO details](https://usaco.org/index.php?page=details), [USACO training](https://usaco.org/index.php?page=training) |
| `NOI China / CNOI` | official `NOI` syllabus PDF on `noi.cn` | Important because it is an official large-scale OI syllabus, but note that the current public document is primarily Chinese | [NOI syllabus PDF](https://www.noi.cn/upload/resources/file/2023/03/15/1fa58eac9c412e01ce3c89c761058a43.pdf) |
| `HKOI` | English-accessible olympiad-aligned syllabus | Helpful English proxy for East Asian OI progression from basics through recursion, divide and conquer, graph theory, and complexity analysis | [HKOI syllabus](https://hkoi.org/en/competition-syllabus/) |
| `APIO / CEOI / BOI / JOI` | official rules and training pages found during research | These reinforce the olympiad side of the repo: partial scoring, subtasks, output-only or communication variants, and stronger emphasis on implementation quality under pressure | [APIO 2025 rules](https://apio2025.uz/rules), [CEOI 2026](https://ceoi2026.acm.si/), [BOI 2025 rules](https://boi2025.mat.umk.pl/rules.php), [JOI Open](https://www.ioi-jp.org/open) |

### Design consequence

The contest side of this repo should stay split instead of pretending all CP is one thing:

- `USACO` favors staged progression
- `IOI` favors individual depth within a syllabus
- `ICPC` favors breadth, speed, and teamwork
- `NOI` and related olympiads reinforce advanced C++ execution and broader task styles

## 4. Primary Learning Platforms and Reference Hubs

These are not all official contest bodies, but they are the strongest current primary resources we found for building a usable repository.

| Resource | Why it matters | How this repo should use it | Notes |
| --- | --- | --- | --- |
| `USACO Guide` | Best top-down roadmap and topic ordering | backbone for sequencing and practice ladders | It explicitly says it is not an official USACO syllabus, so use it as a community curriculum, not as official contest law. [Link](https://usaco.guide/) |
| `CP-Algorithms` | Best encyclopedia-style reference for algorithms and standard implementations | theory/reference layer for almost every category | Public changelog and new-article history show continued updates. [Link](https://cp-algorithms.com/) |
| `CSES` | Best clean practice ladder with strong category coverage | checkpoint problem sets and mixed review rounds | Also useful for teacher-created courses. [Link](https://cses.fi/) |
| `AtCoder` resources | Clean beginner ramp, official platform practice, library testing | beginner onboarding, DP packs, ACL usage, implementation drills | Includes permanent practice and library contests; some famous practice sets are community or volunteer-built rather than official AtCoder curriculum. [Link](https://atcoder.jp/) |
| `Codeforces EDU` | Good stepped drill modules when a lesson exists | drill supplement, not the whole backbone | The public course list feels smaller and more static than the core backbone sites. [Link](https://codeforces.com/edu/courses) |
| `KACTL` | Best notebook-quality verified snippet collection | contest notebook and template-quality bar | Use it for implementation discipline, not as the first teaching surface. [Link](https://github.com/kth-competitive-programming/kactl) |
| `OI Wiki` | Very broad advanced-topic coverage | advanced appendix and enrichment layer | Especially useful for niche or uncommon topics. [Link](https://en.oi-wiki.org/) |

## 5. What We Intentionally Learned From The Research

### A. Early chapters should be practical, not merely theoretical

Foundational syllabi from `MIT`, `Stanford`, `Princeton`, `Cornell`, `Berkeley`, and `UIUC` all converge on a practical early core:

- asymptotics
- data structures
- graph traversals
- greedy
- dynamic programming
- shortest paths
- trees

That is why the README starts with a progression ladder instead of a giant reference taxonomy.

### B. Advanced sections should include theory that many CP repos skip

Official advanced syllabi repeatedly surfaced:

- randomized algorithms
- approximation
- linear programming and duality
- convex or spectral ideas
- hardness and complexity
- algorithm engineering

This repo should eventually teach those as part of the curriculum, not leave them as "maybe later."

### C. String algorithms need deliberate supplementation

Compared with graphs, DP, flows, and optimization, `string algorithms` appeared less prominently in the specific public `2024-2026` university syllabi we found. That does not make them unimportant for CP; it means the repo should intentionally pull them from strong contest/reference ecosystems like `CP-Algorithms`, `OI Wiki`, `ICPC curriculum topics`, and problem archives.

### D. One resource should not be forced to do every job

The research strongly suggests a layered strategy:

- `USACO Guide` for sequencing
- `CP-Algorithms` for explanation and reference
- `CSES` for practice
- `AtCoder` for clean practice sets and library habits
- `KACTL` for notebook standards
- `ICPC` sources for contest habits

That is the design logic behind the README structure.
