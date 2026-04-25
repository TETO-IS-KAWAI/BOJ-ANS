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
    if(left>end||right<start){
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
long long int c;
// int main(){
//     scanf("%d%d", &n, &m, &k);
//     vector<long long> input(n+1);
//     for(int i=1;i<=n;i++){
//         scanf("%lld", &input[i]);
//     }
//     vector<long long> tree(4*n+1);
//     init(input, tree, 1, 1, n);
//     for(int i=0;i<m+k;i++){
//         scanf("%d%d%lld", &a, &b, &c);
//         if(!(a%2)){
//             printf("%lld\n", query(tree, 1, 1, n, b, c));
//         }else{
//             update(input, tree, 1, 1, n, b, c);
//         }
//     }
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    m += k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n-1);
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int index;
            long long val;
            cin >> index >> val;
            update(a, tree, 1, 0, n-1, index-1, val);
        } else if (what == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(tree, 1, 0, n-1, left-1, right-1) << '\n';
        }
    }
    return 0;
}