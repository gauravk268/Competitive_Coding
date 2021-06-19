class Solution
{
public:
  string addStrings(string num1, string num2)
  {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string result = "";
    if (num1.length() < num2.length())
      swap(num1, num2);

    int carry = 0;
    for (int i = 0; i < num1.length(); i++)
    {
      int t1 = 0;
      t1 = num1[i] - '0';
      if (i < num2.length())
        t1 += num2[i] - '0';

      t1 += carry;
      carry /= 10;

      result += (t1 % 10) + '0';
      carry += t1 / 10;
    }

    while (carry)
    {
      result += (carry % 10) + '0';
      carry /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};