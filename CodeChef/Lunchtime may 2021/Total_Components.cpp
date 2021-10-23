#include <bits/stdc++.h>
#define int long long int
using namespace std;
 vector<int>v;
 void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            v.push_back(p);
}
 int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        SieveOfEratosthenes(n);
        set<int>s;
        int ans=0;
        int lc=1;
        int count=0;
        for(int i=0;i<v.size();i++){
            lc=(v[i]*lc)/(__gcd(v[i],lc));
            if(((int)n/v[i])!=1)
            ans+=(n/v[i]);
            else if(((int)n/v[i])==1 && n!=v[i])
            count++;
            if(lc!=1)
            ans-=(n/lc);
            s.insert(ans);
        }
        cout<<count+1<<"\n";
    }
return 0;
}