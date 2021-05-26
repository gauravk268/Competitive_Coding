class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<long long> s;
    for (auto x : tokens)
    {

      if (x == "+")
      {
        long long t1 = s.top();
        s.pop();
        long long t2 = s.top();
        s.pop();
        s.push(t1 + t2);
      }
      else if (x == "-")
      {
        long long t1 = s.top();
        s.pop();
        long long t2 = s.top();
        s.pop();
        s.push(t2 - t1);
      }
      else if (x == "*")
      {
        long long t1 = s.top();
        s.pop();
        long long t2 = s.top();
        s.pop();
        s.push(t1 * t2);
      }
      else if (x == "/")
      {
        long long t1 = s.top();
        s.pop();
        long long t2 = s.top();
        s.pop();
        s.push(t2 / t1);
      }
      else
      {
        long long t1 = stoll(x);
        s.push(t1);
      }
    }

    return s.top();
  }
};