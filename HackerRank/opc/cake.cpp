#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N, K, i, j, size;
        cin>>N>>K;
        
        long long int arr[N], result=0, result1=0;
        
        for(i=0; i<N; i++)
            cin>>arr[i];
        
        size = N-K;
        
        //i=0; j=N-1;
        
        // while(K--){
        //     if((arr[i] | arr[i+1]) > (arr[j] | arr[j-1]))
        //         arr[j--] = 0;
        //     else
        //         arr[i++] = 0;
        // }
        
        for(i=0; i<K; i++){
            for(j=i; j<i+size; j++){
                result1 |= arr[j];
            }
            if(result1>result)
                result = result1;
        }
        
        // int temp = 0;
        // for(temp = i; temp <= j; temp++)
        //     result|= arr[temp];

        cout<<result<<"\n";
    }
    return 0;
}