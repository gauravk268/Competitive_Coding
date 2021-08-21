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
  int numLen, sum;
  cin >> numLen >> sum;

  if (sum == 0 && numLen == 1)
  {
    cout << "0 0" << endl;
    return;
  }
  else if (sum == 0 || sum > 9 * numLen)
  {
    cout << "-1 -1" << endl;
    return;
  }

  vi maxNum(numLen), minNum(numLen);

  int i = 0;
  for (i = 0; i < numLen && sum > 9; i++)
  {
    maxNum[i] = 9;
    minNum[i] = 9;

    sum -= 9;
  }

  if (i + 1 == numLen)
  {
    if (sum)
    {
      maxNum[i] = sum;
      minNum[i] = sum;
    }
    else{
      maxNum[i] = 0;
      minNum[i] = 1;
      minNum[i - 1] -= 1;
    }
  }
  else{
    if(sum){
      maxNum[i] = sum;
      maxNum[numLen-1] = 0;
      minNum[numLen-1] = 1;
      minNum[i] = sum-1;
      i++;

      for (int j = i; j < numLen - 1; j++){
        minNum[j] = 0;
        maxNum[j] = 0;
      }
    }
    else{
      maxNum[numLen-1] = 0;
      minNum[numLen-1] = 1;
      minNum[i] -= 1;

      for (int j = i+1; j < numLen - 1; j++){
        minNum[j] = 0;
        maxNum[j] = 0;
      }
    }
  }

  reverse(all(minNum));
  trav(x, minNum)
  {
    cout << x;
  }
  cout << dotl;
  trav(x, maxNum)
  {
    cout << x;
  }
  cout << endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

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

2
2 15
3 0

69 96
-1 -1

*/