#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> que;
vector<int> adj[32001];
int dim[32001];
int n, m, a, b;
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        dim[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!dim[i])que.push(i);
    }
    while(!que.empty()){
        int piv=que.front();
        que.pop();
        printf("%d ", piv);

        for(int v : adj[piv]){
            dim[v]--;
            if(!dim[v]){
                que.push(v);
            }
        }
    }
}