/*
调用 next_permutation的全排列 
*/ 
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int N = 11;
	int iArr[N];
    for(int i=0; i<N; i++){
        iArr[i] = i+1;
    }
    
    do{
        for(int i=0; i<N; i++){
            cout<<iArr[i];
        }
        cout<<endl;
    }while(std::next_permutation(iArr, iArr+N));
	
	return 0;
}
