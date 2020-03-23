#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin>>testCases;
    int T = testCases;
    
    while(testCases--){
        long long int N, B;
        
        cin>>N>>B;
        
        int A[N];
        
        for(int i =0; i<N; i++){
            cin>>A[i];
        }
        
        sort(A, A+N);
        
        int count=0, sum=0;
        
        if(A[0] > B)
            count = 0;
        else if( A[0] == B )
            count = 1;        
        else{
            for(int i =0; i<N; i++){
                if((sum + A[i]) > B)
                    break;
                count++;
                sum+=A[i];
            }
        }
        
        cout<<"Case #"<<T - testCases<<": "<<count<<"\n";
    }
}