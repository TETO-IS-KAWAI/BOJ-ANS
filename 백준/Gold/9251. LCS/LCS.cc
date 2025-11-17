#include <bits/stdc++.h>
using namespace std;
int table[1010][1010];
int main(){
    ios::sync_with_stdio(false);
    string A, B;
    cin>>A>>B;
    for(int i=1;i<=A.length();i++){
        for(int j=1;j<=B.length();j++){
            if(A[i-1]==B[j-1])
                table[i][j]=table[i-1][j-1]+1;
            else
                table[i][j]=max(table[i-1][j], table[i][j-1]);
        }
    }
    cout<<table[A.length()][B.length()];
    return 0;
}