#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"


const int MOD = 1e9 + 7;
const int SIZE_INT = 16;


void solve()
{
    int n;
    cin >> n;

    unordered_map<int, int> x, y;

    int resA, resB;
    for (int i = 0; i < (4 * n) - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        x[a]++;
        y[b]++;
    }

    cout << resA << " " << resB << endl;
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

/*
1
2
1 1
1 3
4 6
2 1
9 6
9 3
4 3
*/