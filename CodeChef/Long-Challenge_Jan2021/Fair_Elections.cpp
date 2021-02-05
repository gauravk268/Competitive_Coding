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
  ll m, n;
  cin >> n >> m;

  vector<int> a(n), b(m);
  fr(i, n) cin >> a[i];
  fr(i, m) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());

  int count = 0;
  ll sumA = accumulate(a.begin(), a.end(), 0);
  ll sumB = accumulate(b.begin(), b.end(), 0);

  while (sumA <= sumB && count < min(m, n)){
    sumA = (sumA - a[count]) + b[count];
    sumB = (sumB - b[count]) + a[count];

    count++;
  }

  if(sumA <= sumB){
    cout << "-1" << endl;
  }
  else{
    cout << count << endl;
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

Example Input
2
2 3
2 2
5 5 5
4 3
1 3 2 4
6 7 8
Example Output
2
1

*/