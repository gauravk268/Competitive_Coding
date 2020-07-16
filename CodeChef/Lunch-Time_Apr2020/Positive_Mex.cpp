#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)

const int MOD = 998244353;
const int SIZE_INT = 16;
const int MAX = 100005;

ll power[MAX];



void solve()
{
    int N;
    cin>>N;
    
    power[0] = 1;
    for(int i=1; i<MAX; i++){
        power[i] = ( 2*power[i-1] )%MOD;
    }

    ll input[N];
    unordered_map<ll, ll> count;

    //input + update map
    FoR(i, N){
        cin>>input[i];
        count[input[i]]++;
    }

    ll ans=0, sum=0, prod=1;
    long long newMex;
        for(int mex = 1; mex <= N+1; mex++){
 
            // running sum = num 1s + num2s +...numXs
            sum = (sum + count[mex])%MOD;
 
            newMex = (mex*prod)%MOD;
            newMex = (newMex*power[N-sum])%MOD;
 
            //update answer
            ans = (ans + newMex)%MOD;
 
            // running prod = [2^(num 1s) - 1]*....
            prod = (prod*(power[count[mex]]-1))%MOD;
        }

    cout<<ans%MOD<<"\n";
}

int main()
{
    //two lines to speed-up
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    // solve();

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        solve();
    }

    return 0;
}