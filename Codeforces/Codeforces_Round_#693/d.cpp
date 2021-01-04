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
  ll n;
  cin >> n;
  vector<ll> even, odd;

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;

    if (temp & 1)
    {
      odd.push_back(temp);
    }
    else
    {
      even.push_back(temp);
    }
  }

  sort(odd.begin(), odd.end(), greater<ll>());
  sort(even.begin(), even.end(), greater<ll>());

  if (even.size() == 0 && odd.size() >= 2)
  {
    cout << "Bob\n";
    return;
  }
  else if (odd.size() == 0 && even.size() >= 1)
  {
    cout << "Alice\n";
    return;
  }

  int i = 0, j = 0, flag = 1;
  ll resA = 0, resB = 0;
  while (i < even.size() && j < odd.size())
  {
    if (flag == 1)
    {
      if (even[i] < odd[j])
      {
        j++;
      }
      else
      {
        resA += even[i];
        i++;
      }

      flag = 2;
    }
    else
    {
      if (odd[j] < even[i])
      {
        i++;
      }
      else
      {
        resB += odd[j];
        j++;
      }

      flag = 1;
    }
  }

  if (i >= even.size())
  {
    while (j < odd.size())
    {
      if (flag == 1)
      {
        flag = 2;
      }
      else
      {
        resB += odd[j];
        flag = 1;
      }

      j++;
    }
  }

  if (j >= odd.size())
  {
    while(i < even.size()){
      if (flag == 1)
      {
        resA += even[i];
        flag = 2;
      }
      else
      {
        flag = 1;
      }

      i++;
    }
  }

  if (resA == resB)
  {
    cout << "Tie\n";
  }
  else if (resA > resB)
  {
    cout << "Alice\n";
  }
  else
  {
    cout << "Bob\n";
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

inputCopy
4
4
5 2 7 3
3
3 2 1
4
2 2 2 2
2
7 8
outputCopy
Bob
Tie
Alice
Alice

*/