#include <bits/stdc++.h>
using namespace std;
void init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
    }else{
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}
void update(vector<long long> &a, vector<long long> &tree, int node, int start, int end, int index, long long val){
    if(index<start||index>end){
        return;
    }
    if(start==end){
        a[index]=val;
        tree[node]=val;
        return;
    }
    update(a, tree, node*2, start, (start+end)/2, index, val);
    update(a, tree, node*2+1, (start+end)/2+1, end, index, val);
    tree[node]=tree[node*2]+tree[node*2+1];
}
long long query(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(right<start||end<left){
        return 0;
    }
    if(left<=start&&end<=right){
        return tree[node];
    }
    long long lsum=query(tree, node*2, start, (start+end)/2, left, right);
    long long rsum=query(tree, node*2+1, (start+end)/2+1, end, left, right);
    return lsum+rsum;
}
int n, m, k, a, b;
long long c;
int main(){
    scanf("%d%d%d", &n, &m, &k);
    vector<long long> input(n);
    vector<long long> tree(4*n);
    m+=k;
    for(int i=0;i<n;i++){
        scanf("%lld", &input[i]);
    }
    init(input, tree, 1, 0, n-1);
    for(int i=0;i<m;i++){
        scanf("%d%d%lld", &a, &b, &c);
        if(a==1){
            update(input, tree, 1, 0, n-1, b-1, c);
        }else{
            printf("%lld\n", query(tree, 1, 0, n-1, b-1, c-1));
        }
    }
}