class Solution
{
public:
  bool check(bitset<26> &a, bitset<26> &b)
  {
    for (int i = 0; i < 26; i++)
    {
      if (a[i] && b[i])
        return false;
    }
    return true;
  }

  int maxProduct(vector<string> &words)
  {
    int n = words.size();
    vector<bitset<26>> count(n);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
      for (auto c : words[i])
      {
        count[i][c - 'a'] = 1;
      }

      for (int j = 0; j < i; j++)
      {
        if (check(count[i], count[j]))
        {
          cout << i << " " << j << endl;
          result = max(result, (int)(words[i].length() * words[j].length()));
        }
      }
    }

    return result;
  }
};