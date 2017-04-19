/*
全排列枚举超时 
*/
class Solution {
public:
    int isBeauti(int* iArr, int N){
        for(int i=1; i<=N; i++){
            if(iArr[i-1]%i!=0 && i%iArr[i-1]!=0){
                return 0;
            }
        }
        return 1;
    }
    
    int countArrangement(int N) {
        //N = 3;
        int iArr[N];
        int count=0;
        for(int i=0; i<N; i++){
            iArr[i] = i+1;
        }
        do{
            count += isBeauti(iArr, N);
            /*for(int i=0; i<N; i++){
                cout<<iArr[i];
            }
            cout<<endl;*/
        }while(std::next_permutation(iArr, iArr+N));
        
        return count;
    }
};