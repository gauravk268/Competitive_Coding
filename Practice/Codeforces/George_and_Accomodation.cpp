// https://codeforces.com/problemset/problem/467/A

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
    int n;
    cin>>n;

    int p, q, count=0;
    FoR(i, n){
        cin>>p>>q;
        if(q-p >= 2)
            count++;
    }

    cout<<count<<"\n";
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