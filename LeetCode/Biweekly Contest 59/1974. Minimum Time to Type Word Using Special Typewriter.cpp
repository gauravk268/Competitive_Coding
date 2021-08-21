#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minTimeToType(string word)
  {
    int result=0;
    int last=0;

    for(int i=0; i<word.length(); i++)
    {
      int dx=word[i]-'a';
      int k=min(abs(last-dx), 26-abs(dx-last));
      result += k;

      last = dx;
    }

    return result+word.length();
  }
};