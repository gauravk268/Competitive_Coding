#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define ll long long

int main(){
    int testCases;
    cin>>testCases;
    
    while(testCases--){
        ll N, Q, P;
        cin>>N>>Q;

        ll A[N], even=0, odd=0;

        for(int i=0; i<N; i++){
            scanf("%lld", &A[i]);
            int temp;
            temp = __builtin_popcount(A[i]);

            if(temp%2 == 1)
                odd++;
            else
                even++;
        }

        while(Q--){
            ll evenResult=0, oddResult=0;
            scanf("%lld", &P);

            ll value = __builtin_popcount(P);
            
            if(value%2 == 1){
                evenResult = odd;
                oddResult = even;
            }
            else{
                evenResult = even;
                oddResult = odd;
            }
            
            printf("%lld %lld\n", evenResult, oddResult);
        }
    }
    
    return 0;
}

/*
in decimal
odd ^ odd = even
odd ^ even = odd
even ^ odd = odd
even ^ even = even

in binary
odd ^ odd = even
odd ^ even = odd
even ^ odd = odd
even ^ even = even
*/