#include <bits/stdc++.h>
#define int long long
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

#define MOD         1000000007
#define nline       '\n'        
#define pb          push_back
#define mp          make_pair
#define fi          first
#define se          second
#define yes         cout<<"YES\n"
#define no          cout<<"NO\n"
#define vi          vector<int>
#define pii         pair<int,int>
#define sz(v)       v.size()
#define lcm(a,b)    (a*b)/(__gcd(a,b))
#define deb(x)      cout<<#x<<" = "<<x<<endl;
#define deb2(x,y)   cout<<#x<<" = "<<x<<' '<<#y<<" = "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" = "<<x<<' '<<#y<<" = "<<y<<' '<<#z<<" = "<<z<<endl;
#define PR(a,n)     cout<<#a<<" = ";for(int _=0;_<n;_++)cout<<a[_]<<' ';cout<<endl;
#define all(v)      v.begin(),v.end()
#define sortv(v)    sort(all(v));
#define sortrev(v)  sort(all(v),greater<int>())
#define maxHeap     priority_queue<int>
#define minHeap     priority_queue<int, vector<int>, greater<int>>

int pow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}

int SumOfDigits(int x)
{
    if (x < 0)return -1;
    int s = 0;
    while(x)
    {
        s += x%10;
        x /= 10;
    }
 
    return s;
}

//lower_bound = first element >= val, end otherwise
//upper_bound = first element > val, end otherwise
//remember 2 pointer , binary search , bits method
//always look for the edges i.e max value ad min value possible

inline void solve()
{
    int n;
    cin>>n;
    pii a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].fi;
        a[i].se=0;
    }

    int cnt=0;
    vector<pii> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].fi!=a[j].fi && (a[i].se)+(a[j].se)<=1 && cnt<n-1)
            {
                ans.pb(mp(i+1,j+1));
                a[i].se=1;
                a[j].se=1;
                cnt++;
            }
        }
    }
    // deb(cnt);
    for(int i=1;i<n;i++)
    {
        if(a[i].se!=1)
        {
            no;
            return;
        }
    }
    yes;
    for(auto x:ans)
    {
        cout<<x.fi<<' '<<x.se<<nline; 
    }

}

signed main()
{
    boost;
    int t=1;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    return 0;
}
