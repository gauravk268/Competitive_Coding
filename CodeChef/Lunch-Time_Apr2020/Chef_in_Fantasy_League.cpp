#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)

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
    int N, S;
    cin>>N>>S;

    int playerCost[N];
    MEM(playerCost, 0, N);


    FoR(i, N)
    {
        cin>>playerCost[i];
    }

    int m=0, n=0, minForward=MOD, minDefender=MOD;
    FoR(i, N)
    {
        int temp;
        cin>>temp;
        if(temp)
        {
            if(minForward > playerCost[m+n])   minForward = playerCost[m+n];
            m++;
        }

        else
        {
            if(minDefender > playerCost[m+n])  minDefender = playerCost[m+n];
            n++;
        }
    }

    if( (S + minDefender + minForward) <= 100 )
        cout<<"yes\n";
    else
    {
        cout<<"no\n";
    }
    

}

int main()
{
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