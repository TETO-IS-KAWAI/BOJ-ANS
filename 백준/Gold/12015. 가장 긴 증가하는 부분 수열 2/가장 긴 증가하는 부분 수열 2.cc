#include <stdio.h>
#include <vector>

std::vector<int> v;
int n, suc;

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &suc);
		
		if(i!=0&&suc<=v.back()){
			*(lower_bound(v.begin(), v.end(), suc))=suc;
			continue;
		}
		v.push_back(suc);
	}
	printf("%d", v.size());
}