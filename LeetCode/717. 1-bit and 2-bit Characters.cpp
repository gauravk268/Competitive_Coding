class Solution
{
public:
  bool isOneBitCharacter(vector<int> &bits)
  {
    bool result = false;
    int n = bits.size();

    for (int i = 0; i < n; i++)
    {
      switch (bits[i])
      {
      case 1:
        if (i != n - 1)
        {
          i++;
        }
        break;
      case 0:
        if (i == n - 1)
        {
          result = true;
        }
        break;
      }
    }

    return result;
  }
};