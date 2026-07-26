import { describe, it, expect } from 'vitest';

import { computeLinearConflicts, computeManhattanDistance } from '../../../algorithms/Npuzzle/algorithm';

describe('computeLinearConflicts', () => {

	const size = 3;
	const snail = [0, 1, 2, 5, 8, 7, 6, 3, 4];
	const classic = [0, 1, 2, 3, 4, 5, 6, 7, 8];

	it('adds 4 for two conflicting pairs on a snail goal', () => {
		const arr = [8, 2, 0, 1, 5, 4, 3, 6, 7];
		expect(computeLinearConflicts(arr, size, snail)).toBe(computeManhattanDistance(arr, size, snail) + 4);
	});

	it('adds nothing when there is no linear conflict', () => {
		const arr = [1, 2, 3, 8, 0, 4, 7, 6, 5];
		expect(computeLinearConflicts(arr, size, snail)).toBe(computeManhattanDistance(arr, size, snail));
	});

	it('adds 2 for a single conflicting pair on a classic goal', () => {
		const arr = [0, 2, 1, 7, 4, 5, 6, 3, 8];
		expect(computeLinearConflicts(arr, size, classic)).toBe(computeManhattanDistance(arr, size, classic) + 2);
	});

	it('adds 4 for two conflicting pairs on a classic goal', () => {
		const arr = [0, 2, 1, 5, 4, 3, 6, 7, 8];
		expect(computeLinearConflicts(arr, size, classic)).toBe(computeManhattanDistance(arr, size, classic) + 4);
	});
});
