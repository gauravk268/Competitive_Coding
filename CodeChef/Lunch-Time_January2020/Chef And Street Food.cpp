#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, i;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        
        int arr[N],i, S, P, V;
        for(i=0; i<N; i++){
            cin>>S>>P>>V;
            
            S++;
            
            P = P/S;
                
            arr[i] = P * V;
        }
        
        sort(arr, arr+N);
        
        cout<<arr[N-1]<<"\n";
            
    }
    return 0;
}