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
        int N, K;
        cin>>N>>K;
        
        int A[N], rem;
        long long int sum=0;
        for(int i =0; i<N; i++){
            cin>>A[i];
            rem = A[i]%K;
            sum += rem;
        }
        
        sum = sum % K;
        
        cout<<sum<<"\n";
        
       
    }
    return 0;
}