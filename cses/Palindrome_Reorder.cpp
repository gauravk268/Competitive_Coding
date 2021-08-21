#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define endl "\n"
#define trav(x, a) for (auto &x : a)
#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE             \
  freopen("t1.txt", "r", stdin); 
  // freopen("o1.txt", "w", stdout);

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7; // used in most problems


void solution()
{
  string a;
  cin >> a;

  unordered_map<char, int> q;

  for (char x : a)
  {
    q[x]++;
  }

  int odd = 0;
  string oddC = "";
  for (char i = 'A'; i < 'Z'; i++)
  {
    if (q[i] % 2)
    {
      odd++;
      oddC = i;
      q[i]--;
    }
  }

  if (odd > 1 || odd && (a.length() % 2 == 0))
  {
    cout << "NO SOLUTION\n";
    return;
  }

  string left = "", right = "";
  for (auto i:q)
  {
    string temp(i.s / 2, i.f);
    left = left + temp;
    right = temp + right;
  }

  string result = ((odd == 1) ? (left + oddC + right) : (left + right));
  cout << result << endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // ONLINE_JUDGE;
  // cin >> t;

  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*



*/