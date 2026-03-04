#include <stdio.h>

int n;
int table[50]={0, 1, 1, };

int main(){
    scanf("%d", &n);
    for(int i=3;i<=n;i++){
        table[i]=table[i-1]+table[i-2];
    }
    printf("%d", table[n]);
}