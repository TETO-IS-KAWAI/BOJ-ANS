#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b, c;
void init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if(start==end)tree[node]=a[start];
    else{
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node]=(tree[node*2]*tree[node*2+1])%1000000007;
    }
}
void update(vector<long long> &a, vector<long long> &tree, int node, int start, int end, int index, long long val){
    if(index<start||end<index)return;
    if(start==end){
        a[index]=val;
        tree[node]=val;
        return;
    }
    update(a, tree, node*2, start, (start+end)/2, index, val);
    update(a, tree, node*2+1, (start+end)/2+1, end, index, val);
    tree[node]=(tree[node*2]*tree[node*2+1])%1000000007;
}
long long query(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(right<start||end<left)return 1;
    if(left<=start&&end<=right)return tree[node];
    long long ltimes=query(tree, node*2, start, (start+end)/2, left, right);
    long long rtimes=query(tree, node*2+1, (start+end)/2+1, end, left, right);
    return (ltimes*rtimes)%1000000007;
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    vector<long long> input(n);
    for(int i=0;i<n;i++){
        scanf("%d", &input[i]);
    }
    vector<long long> times(4*n);
    init(input, times, 1, 0, n-1);
    m+=k;
    for(int i=0;i<m;i++){
        scanf("%d%d%d", &a, &b, &c);
        if(a==1){
            update(input, times, 1, 0, n-1, b-1, c);
        }else{
            printf("%d\n", query(times, 1, 0, n-1, b-1, c-1));
        }
    }
}