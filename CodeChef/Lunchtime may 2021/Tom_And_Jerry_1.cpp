#include <bits/stdc++.h>
#define int long long int
using namespace std;
 
 int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
     int a,b,c,d,k;
     cin>>a>>b>>c>>d>>k;
     int path=0;
     //case 1
    path=abs(c-a)+abs(d-b);
     //case 1
     
     
     if(path<=k && ((k-path)%2==0))
        cout<<"YES\n";
        else cout<<"NO\n";  
    }   
return 0;
}