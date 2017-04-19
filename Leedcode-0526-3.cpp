/*
交换的全排列 
*/
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int countNum = 0; 

void printNum(int N, int n, int* iArr){
	if(n <= 0){
		for(int i=0; i<N; i++){
			printf("%d", iArr[i]);
		}
		printf("\n");
		countNum++;
	}
	else{
		for(int i=0; i<n; i++){
			int temNum;
			temNum = iArr[i];
			iArr[i] = iArr[n-1];
			iArr[n-1] = temNum;
			printNum(N, n-1, iArr);
			temNum = iArr[i];
			iArr[i] = iArr[n-1];
			iArr[n-1] = temNum;
		}
	}
}

int main(){
	int N=5;
	int iArr[N];
	
	for(int i=0; i<N; i++){
		iArr[i] = i + 1;
	}
	
	printNum(N, N, iArr);
	printf("%d个数总共有%d组全排列\n", N, countNum);
	
	return 0;
}
