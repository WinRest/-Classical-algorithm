/*
尝试 nlogn解最长递增子序列 

树状数组尝试思路好像就错了 ，最长递增要求前面最长 ，
树状数组优势在于求和 
*/

#include<cstdlib>
#include<cstdio>
#include<iostream>

using namespace std;
const int maxn=1e5+5;
int a[maxn],c[maxn];
int ans[maxn],sum[maxn];

bool cmp1(int i,int j){
	return a[i]>a[j];
}

int lowbit(int x){return x&(-x);}

int add(int x){
	while(x<maxn){
        sum[x]++;
        x+=lowbit(x);
    }
}

int Sum(int x){
    int ret=0;
    while(x>0){
        ret+=sum[x];
        x-=lowbit(x);
    }
    return ret;
}
int main(){
	for(int i=1;i<maxn;i++)c[i]=i;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(c,c+n,cmp1);
	
	int top=0;
	
	for(int i=0;i<n;i++){
		while(top<n&&a[c[top]]>=a[c[i]])add(a[c[top++]]);
		ans[c[i]]=top-Sum(a[c[i]]-1);
	}
	
	for(int i=0;i<n;i++)
		cout<<a[c[i]]<<" ";
		
	cout<<endl;
	
	for(int i=0;i<n;i++)
		cout<<sum[i]<<" ";
		
	cout<<endl;
	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	
	return 0;
}
