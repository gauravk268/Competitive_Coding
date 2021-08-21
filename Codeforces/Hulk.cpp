// https://codeforces.com/problemset/problem/705/A

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)
#define pb push_back
#define endl "\n"

const int MOD = 1e9+7;
const int SIZE_INT = 16;


void solve()
{
    int n;
    cin>>n;

    string hate="I hate", love="I love", it=" it", that=" that "; 
    FoR(i, n){
        if(i%2 == 0){
            cout<<hate;
        }
        else{
            cout<<love;
        }

        if(i== n-1){
            cout<<it;
        }
        else{
            cout<<that;
        }
    }

    cout<<endl;
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