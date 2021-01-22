#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define dotl " "
#define MOD 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fr(i, n) for (i = 0; i < n; i++)
#define fr1(i, n) for (i = 1; i <= n; i++)

void ways(ll n)
{
  ll sqr = pow(n, 2);
  ll result = (sqr * (sqr - 1) / 2) - (4 * (n - 1) * (n - 2));
  cout << result << endl;
}

void solution()
{
  ll n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    ways(i);
}

int main()
{
  // ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

Input:
8

Output:
0
6
28
96
252
550
1056
1848

*/