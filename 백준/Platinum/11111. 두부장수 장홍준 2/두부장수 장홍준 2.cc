#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 2505
#define INF 1000000000
using namespace std;

int N, M;
int source = 2501, sink = 2502;

int capacity[MAX][MAX] = {}, flow[MAX][MAX] = {}, cost[MAX][MAX] = {};
vector<int> adj[MAX];

char board[51][51];
int costMap[6][6] = {
    {10, 8, 7, 5, 0, 1},
    {8, 6, 4, 3, 0, 1},
    {7, 4, 3, 2, 0, 1},
    {5, 3, 2, 2, 0, 1},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0}
};

void addEdge(int from, int to) {
    adj[from].push_back(to);
    adj[to].push_back(from);
    capacity[from][to] = 1;

    int edgeCost;
    if (from <= 2500 && to <= 2500) {
        char u = board[(from - 1) / M + 1][(from - 1) % M + 1];
        char v = board[(to - 1) / M + 1][(to - 1) % M + 1];
        edgeCost = -costMap[u - 'A'][v - 'A'];
    } else {
        edgeCost = 0;
    }

    cost[from][to] = edgeCost;
    cost[to][from] = -edgeCost;
}

int minCostMaxFlow() {
    int totalCost = 0;
    while (true) {
        bool inQueue[MAX] = {};
        int parent[MAX] = {};
        int dist[MAX];
        fill(dist, dist + MAX, INF);
        dist[source] = 0;

        queue<int> q;
        q.push(source);
        inQueue[source] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            inQueue[current] = false;

            for (int next : adj[current]) {
                if (capacity[current][next] - flow[current][next] > 0 &&
                    dist[current] + cost[current][next] < dist[next]) {
                    dist[next] = dist[current] + cost[current][next];
                    parent[next] = current;
                    if (!inQueue[next]) {
                        q.push(next);
                        inQueue[next] = true;
                    }
                }
            }
        }

        if (!parent[sink]) break;

        int minFlow = INF;
        for (int i = sink; i != source; i = parent[i])
            minFlow = min(minFlow, capacity[parent[i]][i] - flow[parent[i]][i]);

        for (int i = sink; i != source; i = parent[i]) {
            totalCost += minFlow * cost[parent[i]][i];
            flow[parent[i]][i] += minFlow;
            flow[i][parent[i]] -= minFlow;
        }
    }
    return totalCost;
}

int main() {
    scanf("%d %d\n", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) board[i][j] = getchar();
        getchar();
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int node = (i - 1) * M + j;
            if ((i + j) % 2 == 0) {
                addEdge(source, node);
                if (i > 1) addEdge(node, node - M);
                if (i < N) addEdge(node, node + M);
                if (j > 1) addEdge(node, node - 1);
                if (j < M) addEdge(node, node + 1);
            }
            addEdge(node, sink);
        }
    }

    printf("%d", -minCostMaxFlow());
}