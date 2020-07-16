#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int MOD = 1e9 + 7;
const int SIZE_INT = 16;

void solve()
{
    ll x, n;
    cin >> x >> n;

    vector<ll> country;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;

        country.push_back(temp);
    }

}

int main()
{
    //a line to speed-up
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testCases = 1;
    cin >> testCases; //remove it if only 1 testcase
    while (testCases--)
    {
        solve();
    }

    return 0;
}