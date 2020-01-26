#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int  countLoop=0;

int countSetBits(long long int n) { 
    int last, count=0; 
    while (n) {
        count += n & 1;
        n >>= 1;
        countLoop++;
    }
    if(countLoop == count)  return 0;
    else return 1;
} 

int main() {
    int T;
    cin>>T;
    while(T--){
        long long int N, K=0;
        cin>>N;
        int flag;
        
        flag = countSetBits(N);

        if(flag){
            while(--countLoop){
                K <<= 1;
                K = K | 1;
                //cout<<K<<"\n";
                //K <<= 1;
            }
            
            if(K <= N) cout<<K;
            else cout<<N;
        }
        else    cout<<N;
        
        cout<<"\n";
        countLoop=0;
        
    }
    return 0;
}