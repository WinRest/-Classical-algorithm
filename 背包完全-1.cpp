/*
��N����Ʒ��һ������ΪV�ı�����ÿ����Ʒ�������޼����á���i����Ʒ�������c����ֵ��w��
����Щ��Ʒװ�뱳����ʹ��Щ��Ʒ������ܺͲ����������������Ҽ�ֵ�ܺ����

�Լ۱Ƚ�������̰��+���ݿ������μ��������� 3�� 
������ô������
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
	
	//�Լ۱Ƚ�������̰��+����
	double cosPerSort[N];//costPerformanceSort�Լ۱� 
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
