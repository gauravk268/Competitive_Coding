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

class Solution
{
public:
  char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

  int countVowel(int n, int last)
  {
    int result = 0;

    if (n == 0)
      return 1;

    if (last == 4)
      return 1;

    for (int i = last; i < 5; i++)
    {
      result += countVowel(n - 1, i);
    }

    return result;
  }

  int countVowelStrings(int n)
  {
    return countVowel(n, 0);
  }
};

void solution()
{
  int n;
  cin >> n;
  Solution result;
  cout << result.countVowelStrings(n) << endl;
}

int main()
{
  ONLINE_JUDGE;

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  cerr << t;
  while (t--)
  {
    solution();
  }

  showRunTime;
  return 0;
}

/*

3
1 2 33

Input: n = 1
Output: 5

Input: n = 2
Output: 15

Input: n = 33
Output: 66045

*/