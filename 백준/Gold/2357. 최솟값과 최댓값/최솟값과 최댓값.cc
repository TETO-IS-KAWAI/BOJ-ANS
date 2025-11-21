#include <bits/stdc++.h>
using namespace std;
void init(vector<long long> &a, vector<pair<long long, long long>> &tree, int node, int start, int end){
    if(start==end){
        tree[node].first=tree[node].second=a[start];
    }else{
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node].first=min(tree[node*2].first, tree[node*2+1].first);
        tree[node].second=max(tree[node*2].second, tree[node*2+1].second);
    }
}
long long query1(vector<pair<long long, long long>> &tree, int node, int start, int end, int left, int right){
    if(right<start||end<left){
        return -1;
    }
    if(left<=start&&end<=right){
        return tree[node].first;
    }
    long long lmin=query1(tree, node*2, start, (start+end)/2, left, right);
    long long rmin=query1(tree, node*2+1, (start+end)/2+1, end, left, right);
    if(lmin==-1){
        return rmin;
    }else if(rmin==-1){
        return lmin;
    }else{
        return min(lmin, rmin);
    }
}
long long query2(vector<pair<long long, long long>> &tree, int node, int start, int end, int left, int right){
    if(right<start||end<left){
        return -1;
    }
    if(left<=start&&end<=right){
        return tree[node].second;
    }
    long long lmax=query2(tree, node*2, start, (start+end)/2, left, right);
    long long rmax=query2(tree, node*2+1, (start+end)/2+1, end, left, right);
    if(lmax==-1){
        return rmax;
    }else if(rmax==-1){
        return lmax;
    }else{
        return max(lmax, rmax);
    }
}
int n, m, b;
long long c;
int main(){
    scanf("%d%d", &n, &m);
    vector<long long> input(n);
    vector<pair<long long, long long>> tree(4*n);
    m;
    for(int i=0;i<n;i++){
        scanf("%lld", &input[i]);
    }
    init(input, tree, 1, 0, n-1);
    for(int i=0;i<m;i++){
        scanf("%d%lld", &b, &c);
        printf("%lld %lld\n", query1(tree, 1, 0, n-1, b-1, c-1), query2(tree, 1, 0, n-1, b-1, c-1));
    }
}