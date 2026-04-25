import sys
from collections import deque

min_move_count = {}
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs_from_goal():
    queue = deque()
    initial_state = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
    queue.append([initial_state, 0, 8])
    min_move_count["123456789"] = 0

    while queue:
        state, move_count, blank_index = queue.popleft()
        row, col = divmod(blank_index, 3)

        for dx_i, dy_i in zip(dx, dy):
            new_row, new_col = row + dy_i, col + dx_i
            if not (0 <= new_row < 3 and 0 <= new_col < 3):
                continue

            swap_index = new_row * 3 + new_col
            next_state = state[:]
            next_state[blank_index], next_state[swap_index] = next_state[swap_index], next_state[blank_index]
            state_string = ''.join(next_state)

            if state_string in min_move_count:
                continue
            min_move_count[state_string] = move_count + 1
            queue.append([next_state, move_count + 1, swap_index])

bfs_from_goal()

num_cases = int(sys.stdin.readline().rstrip())
for _ in range(num_cases):
    puzzle_state = []
    sys.stdin.readline().rstrip()
    for _ in range(3):
        row = list(sys.stdin.readline().rstrip())
        for i in range(3):
            if row[i] == '#':
                row[i] = '9'
        puzzle_state += row

    puzzle_string = ''.join(puzzle_state)
    result = min_move_count.get(puzzle_string, "impossible")
    print(result)
