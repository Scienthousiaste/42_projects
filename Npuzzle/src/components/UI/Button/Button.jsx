import React from 'react';

import classes from './Button.module.css';

import Button from '@mui/material/Button';

const button = (props) => (
	<Button onClick={props.clicked} disabled={props.disabled} className={classes.Button} color={props.color} href={null}>{props.children}</Button>
);

export default button;
