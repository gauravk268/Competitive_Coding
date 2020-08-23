#include<bits/stdc++.h>
using namespace std;


#define ENABLE_DEBUG


#define ll long long


#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)
#define pb push_back


const int MOD = 1e9+7;
const int SIZE_INT = 16;


//To print binary equivalent of a binary number
void printBinary(unsigned n)
{
    unsigned i;
    for (i = 1 << 15; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    cout << "\n";
}


// Fast way to calculate power of a large number
ll powerFast(ll a, ll b)
{
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
    
}


int main()
{
	#ifdef ENABLE_DEBUG
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
	
    //two lines to speed-up
    cin.tie(0);
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