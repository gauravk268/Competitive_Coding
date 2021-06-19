class Solution
{
public:
  int addDigits(int num)
  {
    int result = 0;

    while (num)
    {
      result += num % 10;
      num /= 10;
    }

    while (result > 9)
    {
      int temp = result;
      result = 0;
      while (temp)
      {
        result += temp % 10;
        temp /= 10;
      }
    }

    return result;
  }
};