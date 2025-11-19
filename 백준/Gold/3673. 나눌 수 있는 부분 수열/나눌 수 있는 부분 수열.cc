#include <stdio.h>
#include <vector>
#include <algorithm>
int n, d, m, buff, ans;
using namespace std;
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        ans=0;
        scanf("%d%d", &d, &m);
        vector<int> vec(1, 0);
        vector<int> count(d, -1);
        count[0]=0;
        for(int j=1;j<=m;j++){
            scanf("%d", &buff);
            vec.push_back(buff%d);
            vec[j]+=vec[j-1];
            vec[j]%=d;
            count[vec[j]]++;
            ans+=count[vec[j]];
        }
        printf("%d\n", ans);
    }
}