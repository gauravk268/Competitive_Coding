#include <iostream>
#include <string.h>
#include <bitset>
using namespace std;

#define ll long long
#define mod 1000000007
#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SIZE_INT 16

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 15; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    cout << "\n";
}

void solve()
{
    ll N, Q, floorCount;
    cin>>N>>Q;
    
    ll floorInit=0, floorEnd=0, temp=0;
    
    cin>>floorInit>>floorEnd;
    floorCount = floorInit;
    while(--Q){
        floorCount += abs(floorEnd - floorInit);
        temp = floorEnd;
        cin>>floorInit>>floorEnd;
        floorCount += abs(temp - floorInit);
    }
    floorCount += abs(floorEnd - floorInit);
    
    cout<<floorCount<<"\n";
}

int main()
{
    //solve();

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        solve();
    }
    return 0;
}