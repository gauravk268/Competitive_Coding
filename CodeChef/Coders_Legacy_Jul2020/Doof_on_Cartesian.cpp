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
    int n, maxValue = 0;
    cin >> n;

    vector<int> walls(n);

    for(auto &index : walls)
    {
        cin>>index;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        int points = a + b;

        if(binary_search(walls.begin(), walls.end(), points))
            cout<<-1<<endl;
        else
            cout<< lower_bound(walls.begin(), walls.end(), points) - walls.begin() <<endl;
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