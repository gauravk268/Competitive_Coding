#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int gcd(int a, int b)
  {
    if(b==0)  return a;
    
    return gcd(b, a%b);
  }

  int findGCD(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int a = *nums.begin(), b = nums.back();
    return gcd(a, b);
  }
};