#include <bits/stdc++.h>
using namespace std;
#define int         long long 

int32_t main(){
    int T = 1;
    cin>>T;
    while(T--) {
        int n,ans=0;  cin>>n>>ans;     
        int value=((n*(n+1))/2-ans>0)?((n*(n+1))/2-ans):-1;
        if(!(value>0&&value<=n))value=-1;
        cout <<value<<'\n';
    }
    return 0;
}
