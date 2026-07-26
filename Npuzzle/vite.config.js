import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';

// The old ejected CRA config ran every .css/.less file through CSS Modules, which is
// why components do `import classes from './X.less'`. Vite keys CSS Modules off the
// `.module.*` filename instead, so those stylesheets were renamed to `*.module.less`
// / `*.module.css`. `src/index.css` stays global and is imported for side effects.
export default defineConfig({
	plugins: [react()],
	server: {
		port: 3000,
		open: true,
	},
	build: {
		outDir: 'build',
	},
	test: {
		environment: 'jsdom',
		globals: true,
		setupFiles: ['./vitest.setup.js'],
	},
});
