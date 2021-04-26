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
#define ONLINE_JUDGE                \
  freopen("input.txt", "r", stdin); \
  // freopen("output.txt", "w", stdout);

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7; // used in most problems

void solution()
{
  string str;
  cin >> str;

  sort(str.begin(), str.end());
  vector<string> result = {str};
  string temp = str;

  while (true)
  {
    next_permutation(str.begin(), str.end());
    if (temp == str)
    {
      break;
    }
    result.pb(str);
  }

  cout << result.size() << endl;
  for (auto x : result)
  {
    cout << x << endl;
  }
}

string nextPer(string str)
{
  int n = str.length(), i = n - 1;
  while (i > 0 && str[i - 1] >= str[i])
  {
    i--;
  }

  if (i <= 0)
  {
    return " ";
  }

  int j = n - 1;
  while (j > i && str[j] <= str[i - 1])
  {
    j--;
  }

  swap(str[i - 1], str[j]);
  reverse(str.begin() + i, str.end());
  return str;
}

void solution1()
{
  string str;
  cin >> str;

  sort(str.begin(), str.end());
  vector<string> result = {str};
  string tmp = str;

  while (true)
  {
    tmp = nextPer(tmp);
    if (tmp == " ")
    {
      break;
    }
    result.pb(tmp);
  }

  cout << result.size() << endl;
  for (auto x : result)
  {
    cout << x << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // ONLINE_JUDGE;
  // cin >> t;

  while (t--)
  {
    solution1();
  }

  showRunTime;
  return 0;
}

/*

aabac

20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa

*/