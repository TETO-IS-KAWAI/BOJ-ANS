#include <bits/stdc++.h>
using namespace std;
int n, W;
int dp[100001];

int main(){
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        int w, v;
        cin >> w >> v;
        for(int j = W; j >= w; j--){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[W];
}
