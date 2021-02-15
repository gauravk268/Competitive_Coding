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
const int N = 1e6 + 5;
const int MOD = 1e9 + 7; // used in most problems
const ld PI = acos(-1);  // inverse cos of -1

int spf[N];
vi adj[N];
vi value(N);

void sieve()
{
  spf[1] = 1;
  for (int i = 2; i < N; i++)
    spf[i] = i;

  for (int i = 2; i * i < N; i++)
  {
    if (spf[i] == i)
    {
      for (int j = i * i; j < N; j += i)

        if (spf[j] == j)
          spf[j] = i;
    }
  }
}

void getdistinctFactorization(int n)
{
  int index, x, i;
  for (int i = 1; i <= n; i++)
  {
    index = 1;
    x = i;
    if (x != 1)
      adj[i].push_back(spf[x]);
    x = x / spf[x];

    while (x != 1)
    {
      if (adj[i][index - 1] != spf[x])
      {
        adj[i].push_back(spf[x]);
        index += 1;
      }
      x = x / spf[x];
    }
  }
}

void res(int n)
{
  string a[2] = {"Chef", "Divyam"};
  cout << a[n % 2] << endl;
  return;
}

// void solution()
// {
//   int x, y;
//   cin >> x >> y;

//   bool turn = false;
//   int r = 0;

//   while (x)
//   {
//     for (int i = x; i >= 1; i--)
//     {
//       if (adj[i].size() == y)
//       {
//         x -= i;
//         turn ^= 1;
//         r++;

//         if (x<=0)
//         {
//           res(r);
//           return;
//         }
//       }
//     }

//     goto next;
//   }

// next:
//   deb(r);
//   res(r);
//   return;
// }

void solution()
{
  int x, y;
  cin >> x >> y;

  if (value[x] > y)
    cout << "Divyam\n";
  else
    cout << "Chef\n";
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  sieve();
  // getdistinctFactorization(1000004);
  int temp = 0;
  value[1] = temp;
  for (int i = 2; i < N - 1; i++)
  {
    if (spf[i] == i)
    {
      temp++;
    }

    value[i] = temp;
  }

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

/*

Input
3
1 2
3 1
2021 42

Output
Chef
Divyam 
Divyam

*/