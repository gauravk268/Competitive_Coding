class Solution
{
public:
  static bool fun(string &a, string &b)
  {
    string ab = a + b, ba = b + a;
    return ab.compare(ba) > 0;
  }

  string printLargest(vector<string> &arr)
  {
    if (arr.size() == 0)
      return "";
    if (arr.size() == 1)
      return arr[0];

    sort(arr.begin(), arr.end(), fun);

    string result = "";
    for (int i = 0; i < arr.size(); i++)
    {
      result += arr[i];
    }

    return result;
  }
};