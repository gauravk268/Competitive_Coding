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
        long long int a, m, i=0, aGcdm,count = 0;
        cin>>a>>m;

        aGcdm = __gcd(a, m);

        for(i=0; i<m; i++){
            if(__gcd(a+i, m) == aGcdm){
                count++;
            } 
        }
            
        cout<<count<<"\n";
    }
    return 0;
}