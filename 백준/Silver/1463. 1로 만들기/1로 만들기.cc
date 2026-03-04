#include <bits/stdc++.h>
using namespace std;

int table[1000001];
int n;

int forans(int x){
    if(x==1)return 0;
    if(table[x])return table[x];
    table[x]=forans(x-1)+1;
    if(x%3==0)table[x]=min(table[x], forans(x/3)+1);
    if(x%2==0)table[x]=min(table[x], forans(x/2)+1);
    return table[x];
}

int main(){
    table[1]=0;
    table[2]=1;
    scanf("%d", &n);
    printf("%d", forans(n));
}