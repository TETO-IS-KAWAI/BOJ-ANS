#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

vector<int> getPi(string pat){
    int m=pat.size();
    vector<int> result(m);
    int j=0;

    for(int i=1;i<m;i++){
        while(j>0&&pat[j]!=pat[i])
            j=result[j-1];
        if(pat[j]==pat[i])
            result[i]=++j;
    }
    return result;
}

vector<int> kmp(string txt, string pat){
    int n=txt.size(), m=pat.size();
    vector<int> result;
    vector<int> pi=getPi(pat);
    int j=0;

    for(int i=0;i<n;i++){
        while(j>0&&pat[j]!=txt[i])
            j=pi[j-1];
        if(pat[j]==txt[i])
            j++;
        if(j==m)
            result.push_back(i-m+2);
    }
    return result;
}

char buffOne[1000010];
int main(){
    while(true){
        scanf("%s", buffOne);
        if(buffOne[0]=='.')
            return 0;
        string pat(buffOne);
        vector<int> pi=getPi(pat);
        int temp=pat.size()-pi[pi.size()-1];
        if(pat.size()%temp==0)
            printf("%d\n", pat.size()/temp);
        else
            printf("1\n");
    }
}