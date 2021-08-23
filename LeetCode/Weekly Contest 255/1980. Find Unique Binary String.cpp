#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dec(string a)
  {
    int n = a.length();
    int res = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      if (a[i] == '1')
      {
        res = res + pow(2, n - i - 1);
      }
    }

    return res;
  }

  string bin(int a, int n)
  {
    string res = "";
    while (a)
    {
      if (a & 1)
        res += "1";
      else
        res += "0";
      a /= 2;
    }
    while (res.length() < n)
    {
      res += "0";
    }

    reverse(res.begin(), res.end());
    return res;
  }

  string findDifferentBinaryString(vector<string> &nums)
  {
    int n = nums.size();
    int sum = 0;

    set<int> pre;
    for (int i = 0; i < n; i++)
    {
      int tmp = dec(nums[i]);
      pre.insert(tmp);
    }

    int i = 0;
    for (auto &x : pre)
    {
      if (x != i)
      {
        return bin(i, n);
      }

      i++;
    }

    return bin(i, n);
  }
};