#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll primeFactorization(ll X){
    ll count=0;

    while(X%2 == 0){
        X /= 2;
        count++;
    }

    for(int i=3; i*i<X; i++){
        while(X%i == 0){
            X /= i;
            count++;
        }
    }

    if(X>2)
        count++;

    return count;
}

void solve(){
    ll X, K;
    cin>>X>>K;
    
    int flag=0;

    if(X>K){
        ll numPrimeFactor = primeFactorization(X);
        if(numPrimeFactor >= K) flag=1;
    }
        
    if(flag)
        cout<<"1\n";
    else
        cout<<"0\n";
}

int main() {
    int testCases;
    cin>>testCases;
    
    while(testCases--){
        solve();
    }
    
	return 0;
}