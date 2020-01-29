#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        long long int a, m, i=0, aGcdm,count = 0;
        cin>>a>>m;

        aGcdm = __gcd(a, m);

        if(a<100000 && m<100000){
            for(i=0; i<m; i++){
                if(__gcd(a+i, m) == aGcdm){
                    count++;
                } 
            }
            cout<<count<<"\n";
        }
        else
        {
            cout<<max(a, m) -1 <<"\n";
        }
    }
    return 0;
}