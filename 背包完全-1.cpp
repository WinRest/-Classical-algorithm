/*
有N种物品和一个容量为V的背包，每种物品都有无限件可用。第i种物品的体积是c，价值是w。
将哪些物品装入背包可使这些物品的体积总和不超过背包容量，且价值总和最大。

性价比降序排序，贪心+回溯可做，参见完美世界 3题 
不能这么做：如
2 10
9 5
10 5 
*/

#include<cstdlib>
#include<cstdio>
#include<iostream>

using namespace std;

int getAns(int curAns, int restV, int loc, double* cosPerSort, int* c, int* w, int N){
	;
}

int main(){
	int N, volumeM, ans=0;
	scanf("%d %d", &N, &volumeM);
	int c[N], w[N];
	for(int i=0; i<N; i++){
		scanf("%d", &c[i]);
	}
	for(int i=0; i<N; i++){
		scanf("%d", &w[i]);
	}
	
	//性价比降序排序，贪心+回溯
	double cosPerSort[N];//costPerformanceSort性价比 
	for(int i=0; i<N; i++){
		cosPerSort[i] = (double)w[i]/c[i];
	}
	for(int i=0; i<N; i++){
		for(int j=1; j<=i; i++){
			if(cosPerSort[i - 1] < cosPerSort[i]){
				swap(cosPerSort[i - 1], cosPerSort[i]);
			}
		}
	}
	
	return 0;
}
