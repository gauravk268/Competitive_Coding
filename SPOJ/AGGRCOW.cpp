#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<ll> vll;

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define endl "\n"
#define trav(x, a) for (auto &x : a)
#define deb(x) cerr << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE \
  freopen("input.txt", "r", stdin);

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7; // used in most problems

bool fun(vector<int> &value, int cows, int dis)
{
  int count = 1, i = 1, last = 0;
  while (i < value.size())
  {
    if (value[i] - value[last] >= dis)
    {
      last = i;
      count++;
    }

    i++;
  }

  return (count >= cows);
}

void solution()
{
  int house, cow;
  cin >> house >> cow;

  vector<int> value(house);
  for (int i = 0; i < house; i++)
  {
    cin >> value[i];
  }
  sort(value.begin(), value.end());

  int left = 0, right = value[0] + value[house - 1];
  int result = 0;
  while (left <= right)
  {
    int mid = left + ((right - left) >> 1);

    if (fun(value, cow, mid))
    {
      result = mid;
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  cout << result << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // ONLINE_JUDGE;
  cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}