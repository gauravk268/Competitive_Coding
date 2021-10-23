#include <bits/stdc++.h>
#define int long long
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second

inline void solve()
{
    int n;
    cin>>n;
    int a[n];
   
    priority_queue<int, vector<int>, greater<int>> pq;

    int health=0;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        health+=x;

        pq.push(x);

        if(health<0)
        {
            health = health - pq.top();             //if the health is neg remove the most negative number 
            pq.pop();
        }
    }
    cout<<pq.size();
    return;
    
}

signed main()
{
    boost;
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}