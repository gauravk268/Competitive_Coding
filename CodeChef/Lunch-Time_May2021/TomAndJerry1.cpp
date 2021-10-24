#include <bits/stdc++.h>
using namespace std;
#define FAST        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int         long long int
#define yes         cout<<"YES"<<endl 
#define no          cout<<"NO"<<endl

int32_t main(){FAST;
    int T = 1;cin >> T;
    while(T--) {
        int n,ans=0,a,b,c,d,k; 
        cin>>a>>b>>c>>d>>k;      
        ans=abs(a-c)+abs(b-d);
        if(ans<=k&&(ans-k)%2==0)yes; else no;
    }
    return 0;
}