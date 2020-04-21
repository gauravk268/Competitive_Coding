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
        long long int c, n, sum, remain;
        cin>>c>>n;
        
        sum = (n*(n+1))/2;
        sum -= n;
        
        remain = c - sum;
        //cout<<remain<<"\n";
        
        if(remain < n)
            cout<<c;
        else
            cout<<remain%n;
            
        cout<<"\n";
        
        
    }    
    return 0;
}