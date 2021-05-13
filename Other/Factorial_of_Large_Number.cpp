#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> factorial(int N)
  {
    vector<int> result = {1};
    int carry = 0;

    for (int i = 2; i <= N; i++)
    {
      int k = result.size();
      for (int j = 0; j < k; j++)
      {
        int prod = result[j] * i + carry;
        result[j] = prod % 10;
        carry = prod / 10;
      }

      while (carry)
      {
        result.push_back(carry % 10);
        carry /= 10;
      }

      // cout << N << " " << i << ": ";
      // for (auto x : result)
      //   cout << x;
      // cout << endl;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};
// 10 1 2 3 4 5 6 7 8 9 10
// 2432902008176640000

int main()
{
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int N = 1000;
    // cin >> N;
    Solution ob;
    vector<int> result = ob.factorial(N);
    for (int i = 0; i < result.size(); ++i)
    {
      cout << result[i];
    }
    cout << endl;
  }
  return 0;
}