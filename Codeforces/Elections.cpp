#include <bits/stdc++.h>
using namespace std;
#define int         long long 

int32_t main(){
    int T = 1;
    cin>>T;
    while(T--) {
        int n,ans=0,a,b,c;  cin>>a>>b>>c;      
        cout<<max(0LL,max(b,c)+1LL-a)<<" ";
        cout<<max(0LL,max(a,c)+1LL-b)<<" ";
        cout<<max(0LL,max(b,a)+1LL-c)<<" ";
        cout <<'\n';
    }
    return 0;
}
