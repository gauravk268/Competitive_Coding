#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back
#define ll long long
#define endl "\n"

const int MOD = 1e9 + 7;
const int SIZE_INT = 16;


void solve()
{
    int n;
    cin >> n;

    vector<ll> a, b, values;

    ll temp, costA = 0, costB = 0;

    cin >> temp;
    a.push_back(temp);
    values.push_back(temp);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;

        if (find(a.begin(), a.end(), temp) == a.end())
        {
            a.push_back(temp);
        }
        else if (find(b.begin(), b.end(), temp) == b.end())
        {
            b.push_back(temp);
            costA++;
        }

        auto it = find(values.begin(), values.end(), temp);
        if (it == values.end())
        {
            values.push_back(temp);
        }
        else
        {
            values.erase(it);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        if (find(b.begin(), b.end(), temp) == b.end())
        {
            b.push_back(temp);
        }
        else if (find(a.begin(), a.end(), temp) == a.end())
        {
            a.push_back(temp);
            costB++;
        }

        auto it = find(values.begin(), values.end(), temp);
        if (it == values.end())
        {
            values.push_back(temp);
        }
        else
        {
            values.erase(it);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (values.empty())
    {
        if(costA > costB)
        {
            cout << costA << endl;
        }
        else
        {
            cout << costB << endl;
        }
    }
    else
    {
        cout << "-1" << endl;
    }

    a.clear();
    b.clear();
    values.clear();
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