import { describe, it, expect } from 'vitest';

import PriorityQueue from '../../../helpers/Npuzzle/PriorityQueue';

describe('PriorityQueue', () => {

	it('starts empty and stops being empty once something is enqueued', () => {
		const pq = new PriorityQueue();
		expect(pq.isEmpty()).toBe(true);
		pq.enqueue('10', 10);
		expect(pq.isEmpty()).toBe(false);
	});

	it('dequeues in non-decreasing priority order', () => {
		const pq = new PriorityQueue();
		[['10', 10], ['3', 3], ['2', 2], ['5', 5], ['50', 50], ['20', 20],
			['11', 11], ['5bis', 5], ['50bis', 50], ['1', 1], ['5tierce', 5]]
			.forEach(([content, priority]) => pq.enqueue(content, priority));

		let oldPriority = pq.dequeue().priority;
		while (!pq.isEmpty()) {
			const node = pq.dequeue();
			expect(node.priority).toBeGreaterThanOrEqual(oldPriority);
			oldPriority = node.priority;
		}
	});
});
