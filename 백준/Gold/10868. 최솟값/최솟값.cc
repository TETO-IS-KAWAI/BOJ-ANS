#include <bits/stdc++.h>
using namespace std;
int n, m, b, c;
void init(vector<int> &a, vector<int> &tree, int node, int start, int end){
    if(start==end)tree[node]=a[start];
    else{
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node]=min(tree[node*2], tree[node*2+1]);
    }
}
long long query(vector<int> &tree, int node, int start, int end, int left, int right){
    if(right<start||end<left)return -1;
    if(left<=start&&end<=right)return tree[node];
    long long lmin=query(tree, node*2, start, (start+end)/2, left, right);
    long long rmin=query(tree, node*2+1, (start+end)/2+1, end, left, right);
    if(lmin==-1)return rmin;
    else if(rmin==-1)return lmin;
    else return min(lmin, rmin);
}
int main(){
    scanf("%d%d", &n, &m);
    vector<int> input(n);
    for(int i=0;i<n;i++){
        scanf("%d", &input[i]);
    }
    vector<int> times(4*n);
    init(input, times, 1, 0, n-1);
    for(int i=0;i<m;i++){
        scanf("%d%d", &b, &c);
        printf("%d\n", query(times, 1, 0, n-1, b-1, c-1));
    }
}