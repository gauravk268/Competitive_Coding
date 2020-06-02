// https://codeforces.com/problemset/problem/617/A

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)
#define pb push_back

const int MOD = 1e9+7;
const int SIZE_INT = 16;


void solve()
{
    ll n;
    cin>>n;

    if(n>=1 && n<=5){
        cout<<"1\n";
    }
    else{
        if(n%5 == 0){
            cout<<n/5<<"\n";
        }
        else{
            cout<<n/5 + 1<<"\n";
        }
    }
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

    return 0;
}