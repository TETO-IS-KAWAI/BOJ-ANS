#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int main(){
    scanf("%d", &n);
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        scanf("%d", &vec[i]);
    }

    vector<int> ans(vec);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for(int val : vec){
        auto iter=lower_bound(ans.begin(), ans.end(), val);
        printf("%d ", distance(ans.begin(), iter));
    }
}