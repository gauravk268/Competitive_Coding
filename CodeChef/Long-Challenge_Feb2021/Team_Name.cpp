#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define bk back()
#define pb push_back
#define endl "\n"
#define dotl " "

#define fr1(i, a, b) for (int i = (a); i <= (b); ++i)
#define fr(i, a) fr1(i, 0, a)
#define rf1(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define rf(i, a) rf1(i, 0, a)
#define trav(x, a) for (auto &x : a)

#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

const int MX = 2e5 + 5;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7; // used in most problems
const ld PI = acos(-1);  // inverse cos of -1

void solution()
{
  int n;
  cin >> n;

  vector<string> pre(n), suf(n);
  unordered_map<char, vector<string>> charHash;
  unordered_map<string, int> hash;
  for (int i = 0; i < n; i++)
  {
    string x;
    cin >> x;
    hash[x]++;

    pre[i] = x.substr(0, 1);
    suf[i] = x.substr(1, x.length() - 1);
    charHash[x[0]].pb(suf[i]);
  }

  ll ans = 0;
  string a, b;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (pre[i] == pre[j] || suf[i] == suf[j])
      {
        continue;
      }

      a = pre[i] + suf[j];
      b = pre[j] + suf[i];

      if (hash[a] == 0 && hash[b] == 0)
      {
        ans++;
      }
    }
  }

  cout << 2 * ans << endl;
}

void sol1()
{
  int n;
  cin >> n;

  unordered_map<string, vector<char>> hash;
  unordered_set<string> suf;
  string t, a;
  for (int i = 0; i < n; i++)
  {
    cin >> t;
    a = t.substr(1, t.length() - 1);

    hash[a].pb(t[0]);
    suf.insert(a);
  }

  vector<string> body;
  for (string b : suf)
  {
    sort(hash[b].begin(), hash[b].end());
    body.pb(b);
  }

  string b, c;
  vector<char> d;
  ll result = 0, temp;
  for (int i = 0; i < body.size() - 1; i++)
  {
    for (int j = i + 1; j < body.size(); j++)
    {
      b = body[i];
      c = body[j];
      set_difference(hash[b].begin(), hash[b].end(), hash[c].begin(), hash[c].end(), inserter(d, d.begin()));
      temp = d.size();
      // result += ((temp - hash[b].size()) * (temp - hash[c].size()));
      result += temp;
      d.clear();
    }
  }

  cout << result * 2 << endl;
}

ll fun1(vector<char> a, vector<char> b)
{
  unordered_set<char> m(a.begin(), a.end());
  int ans = 0;
  for (auto alpha : b)
  {
    if (m.find(alpha) != m.end())
    {
      ans++;
    }
  }
  return ans;
}

void sol2()
{
  int n;
  cin >> n;

  unordered_map<string, vector<char>> hash;
  for (int i = 0; i < n; i++)
  {
    string t;
    cin >> t;
    if (t.length() > 1)
    {
      hash[t.substr(1)].pb(t[0]);
    }
  }

  ll result = 0;
  for (auto i : hash)
  {
    for (auto j : hash)
    {
      if (i.f != j.f)
      {
        ll ans = fun1(i.s, j.s);
        result += ((i.s.size() - ans) * (j.s.size() - ans));
      }
    }
  }

  cout << result << endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // ONLINE_JUDGE;
  cin >> t;

  while (t--)
  {
    sol2();
  }

  showRunTime;
  return 0;
}

/*

5
2
suf mas
3
good game guys
4
hell bell best test
2
aba bbb
4
aba bbb baa aab
4
abc def ghi jkl

2
0
2
2
8
12

*/