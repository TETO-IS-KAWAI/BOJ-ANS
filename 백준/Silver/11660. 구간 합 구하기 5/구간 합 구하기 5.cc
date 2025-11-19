#include <stdio.h>
int n, m, arr[1025][1025];
int x_1, x_2, y_1, y_2;
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &arr[i][j]);
            arr[i][j]=arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d", &y_1, &x_1, &y_2, &x_2);
        printf("%d\n", arr[y_2][x_2]-arr[y_1-1][x_2]-arr[y_2][x_1-1]+arr[y_1-1][x_1-1]);
    }
}