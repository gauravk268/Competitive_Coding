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
    int a,b,n;
    cin>>a>>b>>n;
    vi boy(n),grl(n);
    for(int i=0;i<n;i++)
    cin>>boy[i];
    for(int i=0;i<n;i++)
    cin>>grl[i];

    if(n==1)
    {
        cout<<0<<nline;
        return;
    }

    vi cntB(a+1),cntG(b+1);
    // map<pii,int>m;
    for(int i=0;i<n;i++)
    {
        cntB[boy[i]]++;
        cntG[grl[i]]++;
        // m[mp(boy[i],grl[i])]++;
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        // int cnt = m[mp(boy[i],grl[i])];
        ans+= n - (cntB[boy[i]] + cntG[grl[i]] - 1);
    }
    cout<<ans/2<<nline;
    return;




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
