//backtracking

//N-queen_BOJ 9663
#include <stdio.h>
int ans, n, col[16], inc[32], dec[32];

void f(int r){//r is vertical
	if(r>n){
		ans++;
		return;
	}
	
	for(int i=0;i<n;i++){
		if(!col[i]&&!inc[r+i]&&!dec[n+(r-i)]){
			col[i]=inc[r+i]=dec[n+r-i]=1;
			f(r+1);
			col[i]=inc[r+i]=dec[n+r-i]=0;
		}
	}
}

int main(){
	scanf("%d", &n);
	f(1);
	printf("%d", ans);
}