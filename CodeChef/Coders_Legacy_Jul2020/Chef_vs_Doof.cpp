#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define gc getchar_unlocked
#define ll long long
#define endl "\n"

const int MOD = 1e9 + 7;
const int SIZE_INT = 16;

void solve()
{
    int n;
    cin >> n;

    vector<int> values;
    bool flag = true;
    int result = 1;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        values.push_back(temp);
        result *= temp;
    }
    
    if(result%2 == 0)
        flag = false;

    flag ? cout << "YES" << endl : cout << "NO" << endl;
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