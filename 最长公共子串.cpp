/*
��ʵ����һ�����������⣬�����ö�̬�滮����⡣���ǲ���һ����ά��������¼�м�Ľ����
���ǿ������б�Խ�������Ǹ������ҳ�������Ӵ�
��Ҫ�ھ�������1ʱ�������������Ͻ�Ԫ�ؼ�1
�ڹ��������ά����Ĺ��������ڵó������ĳһ�к�����һ�о�û���ˣ�
����ʵ�����ڳ����п�����һά�����������������
Ҳ���Ը���������й����Ӵ� 
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
	//��һ��index[lenMax]������ pMaxLen, pLocMax, pLocMin�Ϳ��������й����Ӵ� 
	
	for(int i=0; i<lenMax; i++){
		p[i] = 0;
	}
	for(int i=0; i<lenMin; i++){ 
		for(int j=lenMax-1; j>=0; j--){//����Ӻ���ǰ������Ḳ�ǵ���һ�н��
			if(strMin[i] == strMax[j]){
				if(j == 0){
					p[j] = 1;
				}
				else{
					p[j] = p[j - 1] + 1;
				}
				//��һ��index[j]�� p[j]�ıȽϣ������й����Ӵ� 
				if(p[j] > pMaxLen){
					pMaxLen = p[i];
					pLocMax = j;
					pLocMin = i;
				}
			}
			else{
				p[j] = 0;
			}
			//��ӡ���������ҷ������� 
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
