import React from 'react';

import classes from './style/App.module.less';

import {BrowserRouter, Routes, Route} from 'react-router';

import Layout from './components/hoc/Layout/Layout';

import Npuzzle from './components/Npuzzle/Npuzzle';

const App = () => {

	return (
		<BrowserRouter>
			<Layout>
				<div className={classes.App}>
					<Routes>
						<Route path={'/'} element={<Npuzzle />} />
					</Routes>
				</div>
			</Layout>
		</BrowserRouter>
	);
};

export default App;
