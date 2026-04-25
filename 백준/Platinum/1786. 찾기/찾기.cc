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

char buffOne[1000010], buffTwo[1000010];
int main(){
    fgets(buffOne, sizeof buffOne, stdin);
    fgets(buffTwo, sizeof buffTwo, stdin);
    for(int i=0;buffOne[i];i++)
        if(buffOne[i]=='\n')
            buffOne[i]='\0';
    for(int i=0;buffTwo[i];i++)
        if(buffTwo[i]=='\n')
            buffTwo[i]='\0';
    string txt(buffOne), pat(buffTwo);
    vector<int> answer=kmp(txt, pat);
    printf("%d\n", answer.size());
    for(int i=0;i<answer.size();i++){
        printf("%d ", answer[i]);
    }
}