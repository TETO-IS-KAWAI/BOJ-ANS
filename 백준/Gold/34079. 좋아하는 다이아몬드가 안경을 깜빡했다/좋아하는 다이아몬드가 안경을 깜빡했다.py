import sys
from collections import deque

def bfs(start, N, edges):
    dist = [float('inf')] * (N+1)
    cnt = [0] * (N+1)
    q = deque()
    dist[start] = 0
    cnt[start] = 1
    q.append(start)
    while q:
        u = q.popleft()
        for v in edges[u]:
            if dist[v] > dist[u] + 1:
                dist[v] = dist[u] + 1
                cnt[v] = cnt[u]
                q.append(v)
            elif dist[v] == dist[u] + 1:
                cnt[v] += cnt[u]
    return dist, cnt

def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    edges = [[] for _ in range(N+1)]
    for _ in range(M):
        u, v = map(int, input().split())
        edges[u].append(v)
        edges[v].append(u)
    dist1, cnt1 = bfs(1, N, edges)
    distN, cntN = bfs(N, N, edges)
    D = dist1[N]
    T = cnt1[N]
    for v in range(2, N):
        if dist1[v] + distN[v] == D and cnt1[v] * cntN[v] == T:
            print(v)
            return
    print(1)

if __name__ == '__main__':
    main()
