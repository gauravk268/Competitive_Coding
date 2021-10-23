#include <bits/stdc++.h>
#define int long long int
using namespace std;
 
 int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,ans=0,k;  cin>>n>>k;       char arr[n+1];   for(int i=0;i<n;i++)cin>>arr[i];
        int a[k+1];
        for(int i=0;i<k;i++)
        cin>>a[i];

        if(n==1)
        for(int i=0;i<k;i++)
        cout<<ans<<'\n';

        if(n>1){
        for(int i=1;i<n;i++)
        if(arr[i]==arr[i-1])ans+=2;
        else ans++;
        for(int i=0;i<k;i++){
            int j=a[i]-1;
            if(j==0){
                if(arr[j]==arr[j+1])ans--;
                else ans++;
            }
            else if(j==n-1){
                if(arr[j]==arr[j-1])
                ans--;
                else ans++;
            }
            else{
                if(arr[j]==arr[j+1])
                ans--;
                else ans++;
                if(arr[j]==arr[j-1])ans--;
                else ans++;
            }
            if(arr[j]=='0')arr[j]='1';
            else arr[j]='0';
            cout<<ans<<'\n';
        }
    }
    }
return 0;
}