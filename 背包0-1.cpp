/*
0-1���� һά����ⷨ 
*/
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int main(){
	int N, weightM, ans=0;//��֪��˭�󣬲�������weightM>=N 
	scanf("%d %d", &N, &weightM);
	int dpLen = N > (weightM + 1) ? N : (weightM + 1);
	int w[N], v[N], dp[dpLen];
	for(int i=0; i<N; i++){
		scanf("%d", &w[i]);
	}
	for(int i=0; i<N; i++){
		scanf("%d", &v[i]);
	}
	
	//��ʼ�� dp
	for(int i=0; i<dpLen; i++){
		dp[i] = 0;
	}
	/*for(int i=0; i<N; i++){
		dp[w[i]] = v[i];
	}*/
	
	//dp�±�:�Ѿ�װ�˶������� 
	for(int i=0; i<N; i++){
		//dp[i] = 0;//��ʼ�� dp
		for(int j=dpLen-1; j>=w[i]; j--){
			if(dp[j] < dp[j - w[i]] + v[i]){
				dp[j] = dp[j - w[i]] + v[i];
				if(ans < dp[j]){
					ans = dp[j];
					//cout<<ans<<endl;
				}
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
