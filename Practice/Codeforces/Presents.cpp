// https://codeforces.com/problemset/problem/136/A

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

    vector<int> gift(n), person(n);
    FoR(i, n){
        cin>>gift[i];
        person[gift[i]-1] = i+1;
    }

    FoR(i, n){
        cout<<person[i];
        if(i==(n-1))
            cout<<endl;
        else
        {
            cout<<" ";
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