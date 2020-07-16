#include <iostream>
#include<string.h>
#include<math.h>
#include<bitset>
using namespace std;

#define ll long long

#define FoR(i, a) for (int i = 0; i < a; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define MEM(a, n) memset(a, n, sizeof(a[0]) * n)

const int MOD = 1e9 + 7;

// Fast way to calculate power of a large number
ll powerFast(ll a, ll b){
    // 3^10 == (3*3)^(10/2)
    // keep on repeating until the power cannot be divided

    a%=MOD;
    ll result =1;
    while(b>0){
        if(b%2 == 1){
            result *= a;
            result %= MOD;
        }

        a*=a;   a%=MOD;
        b/=2;
    }
    
    return result;
}

void solve()
{
    ll N, A;
    cin>>N>>A;

    ll product=1, pval, ans=0;
    for(int i=1; i<=N; i++){
        //pval = (A * product)^(2*i-1)
        //pval = (current value in matrix)^(2*i-1)
        //current value in the matrix = pval * product
        
        pval = powerFast(A*product, 2*i-1);
        ans = (ans+pval)%MOD;
        product = (pval * product)%MOD;
    }
    // ans%=MOD;

    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);

    // solve();

    int testCases;
    cin>>testCases;

    while(testCases--){
        solve();
    }

    return 0;
}