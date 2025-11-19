#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
set<string> parent;
string buff;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>buff;
        parent.insert(buff);
    }
    cin>>m;
    while(!(parent.size()<=n/2)&&ans<m){
        cin>>buff;
        if(parent.end()!=parent.find(buff))parent.erase(buff);
        ans++;
    }
    cout<<ans;
    return 0;
}