// https://projecteuler.net/problem=2

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)
#define pb push_back
#define endl "\n"

const int MOD = 4000000;
const int SIZE_INT = 16;


void solve()
{
    ll count=0,a=1,b=1,i;
    while(true){
        i = a+b;

        if(i > MOD)
            break;

        if(i%2 == 0){
            count += i;
        }

        a=b;
        b=i;
    }

    cout<<count<<endl;
}

int main()
{
    //two lines to speed-up
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();

    // int testCases;
    // cin >> testCases;

    // while (testCases--)
    // {
    //     solve();
    // }

    // return 0;
}