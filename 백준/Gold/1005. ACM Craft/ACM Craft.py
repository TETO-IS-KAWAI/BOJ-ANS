import sys
import heapq
from collections import defaultdict

def find(precede_list, build_next, time, targ):
	queue = [(time[i], i) for i in range(1, len(precede_list)) if precede_list[i] == 0]
	heapq.heapify(queue)
	
	while queue:
		finish_time, building = heapq.heappop(queue)
		if building == targ:
			return finish_time
		
		for next in build_next[building]:
			precede_list[next] -= 1
			
			if precede_list[next] == 0:
				heapq.heappush(queue, (finish_time + time[next], next))

for _ in range(int(sys.stdin.readline())):
	n, k = map(int, sys.stdin.readline().split())
	precede_list = [0 for _ in range(n + 1)]
	build_next = defaultdict(list)

	time = list(map(int, sys.stdin.readline().split()))
	time.insert(0, 0)
	
	for __ in range(k):
		precede, antecede = map(int, sys.stdin.readline().split())
		precede_list[antecede] += 1
		build_next[precede].append(antecede)
	
	targ = int(sys.stdin.readline())
	print(find(precede_list, build_next, time, targ))