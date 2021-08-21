//http://codeforces.com/problemset/problem/339/A

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
    string value;
    cin>>value;

    vector<int> number;
    FoR(i, value.length()){
        if(value[i] == '+')
            continue;
        
        number.pb(value[i]-48);
    }

    sort(number.begin(), number.end());
    int count=number.size();
    FoR(i, number.size()){
        cout<<number[i];
        if(count-1){
            cout<<"+";
            count--;
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