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
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++){
            cin>>A[i];
        }
        
        for(int i=0; i<N; i++){
            cin>>B[i];
        }
        
        sort(A, A+N);
        sort(B, B+N);
        
        long long int sum =0;
        
        for(int i=0; i<N; i++){
            if(A[i] > B[i])
                sum+=B[i];
            else
                sum+=A[i];
        }
        
        cout<<sum<<"\n";
    }
    return 0;
}