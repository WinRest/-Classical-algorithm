/*
其实这是一个序贯决策问题，可以用动态规划来求解。我们采用一个二维矩阵来记录中间的结果。
我们看矩阵的斜对角线最长的那个就能找出最长公共子串
当要在矩阵是填1时让它等于其左上角元素加1
在构造这个二维矩阵的过程中由于得出矩阵的某一行后其上一行就没用了，
所以实际上在程序中可以用一维数组来代替这个矩阵
也可以改造成求所有公共子串 
*/

#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main(){
	string str1, str2;
	cin>>str1>>str2;
	int len1=str1.size(), len2=str2.size(), lenMax, lenMin;
	lenMax = len1 > len2 ? len1 : len2;
	string &strMax = len1 > len2 ? str1 : str2;
	lenMin = len1 < len2 ? len1 : len2;
	string &strMin = len1 < len2 ? str1 : str2;
	int p[lenMax], pMaxLen=0, pLocMax=0, pLocMin=0;
	//用一个index[lenMax]，代替 pMaxLen, pLocMax, pLocMin就可以求所有公共子串 
	
	for(int i=0; i<lenMax; i++){
		p[i] = 0;
	}
	for(int i=0; i<lenMin; i++){ 
		for(int j=lenMax-1; j>=0; j--){//方向从后往前，否则会覆盖掉上一行结果
			if(strMin[i] == strMax[j]){
				if(j == 0){
					p[j] = 1;
				}
				else{
					p[j] = p[j - 1] + 1;
				}
				//加一个index[j]和 p[j]的比较，求所有公共子串 
				if(p[j] > pMaxLen){
					pMaxLen = p[i];
					pLocMax = j;
					pLocMin = i;
				}
			}
			else{
				p[j] = 0;
			}
			//打印矩阵是左右反过来的 
			//printf("%d ", p[j]);
		}
		//printf("\n");
	}
	
	if(pMaxLen == 0){
		printf("No\n");
	}
	else{
		for(int i=pLocMax-pMaxLen; i<=pLocMax; i++){
			printf("%c", strMax[i]);
		}
		printf("\n");
	}
	
	return 0;
}
