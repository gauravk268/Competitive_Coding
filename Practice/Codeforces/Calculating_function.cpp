// https://codeforces.com/problemset/problem/486/A

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
    ll n;
    cin>>n;

    ll numEven, numOdd;
    if(n%2 == 0){
        numEven = n/2;
        numOdd = numEven;
    }
    else{
        numEven = n/2;
        numOdd = numEven+1;
    }

    ll even, odd;
    even = numEven * (numEven+1);
    odd = numOdd*numOdd;
    

    cout<<even-odd<<endl;

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