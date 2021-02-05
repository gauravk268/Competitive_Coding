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
#define fr(i, n) for (int i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 1; i <= n; i++)

void solution()
{
  ll n, k, x, y;
  cin >> n >> k >> x >> y;

  if (x == y)
  {
    cout << n << dotl << n << endl;
    return;
  }
  else if (k == 0)
  {
    cout << x << dotl << y << endl;
    return;
  }
  else if (x > y)
  {
    switch (k % 4)
    {
    case 0:
      cout << (x-y) << dotl << 0 << endl;
      break;
    case 1:
      cout << n << dotl << (n-x+y) << endl;
      break;
    case 2:
      cout << (n-x+y) << dotl << n << endl;
      break;
    case 3:
      cout << 0 << dotl << (x-y) << endl;
      break;
    }
  }
  else
  {
    switch (k % 4)
    {
    case 0:      
      cout << 0 << dotl << (y-x) << endl;
      break;
    case 1:
      cout << (n+x-y) << dotl << n << endl;
      break;
    case 2:
      cout << n << dotl << (n+x-y) << endl;
      break;
    case 3:
      cout << (y-x) << dotl << 0 << endl;
      break;
    }
  }
}

int main()
{
  // ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

Sample Input:
2
5 5 4 4
5 2 3 1
Sample Output:
5 5
3 5

*/