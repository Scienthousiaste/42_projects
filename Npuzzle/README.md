# N-Puzzle solver

A browser N-puzzle (sliding puzzle) visualiser and solver. You can parse a puzzle,
generate a random one, then watch a search algorithm solve it step by step.

## Running it

Requires Node 20.19+ or 22.12+ (Vite 8).

```sh
npm install
npm start       # dev server on http://localhost:3000
npm run build   # production build into build/
npm run preview # serve the production build locally
npm test        # run the test suite (Vitest)
```

## What's in here

- `src/algorithms/Npuzzle/algorithm.js` — the search itself: A\*, weighted A\*, greedy
  and uniform-cost, driven by a priority queue.
- `src/helpers/Npuzzle/` — priority queue, puzzle helpers, shared constants.
- `src/components/Npuzzle/` — the puzzle UI: tile set, playback controls, solver panel.
- `src/components/UI/` — small presentational wrappers (Button, Slider, Modal, ...) over
  [MUI](https://mui.com/) and plain CSS.
- `puzzleGen.py` — standalone script for generating puzzle files to paste into the parser.

### Heuristics

Manhattan distance, linear conflicts, and relaxed adjacency, selectable in the UI along
with a weight for weighted A\*.

### Known limits

See `safeMode` — uniform cost is only practical for 3x3 and smaller; the other
algorithms handle up to 5x5. Large searches are capped by a purge threshold that is
adjustable in the solver panel.

## Build setup

The project was originally an ejected Create React App (webpack 4, Babel 7.4) and was
migrated to [Vite](https://vite.dev/). Two conventions carried over from that setup:

- **Every** stylesheet is a CSS Module, so files are named `*.module.css` /
  `*.module.less` and imported as `import classes from './X.module.less'`.
  `src/index.css` is the one exception — it holds global styles.
- Components containing JSX use the `.jsx` extension, which Vite requires.
