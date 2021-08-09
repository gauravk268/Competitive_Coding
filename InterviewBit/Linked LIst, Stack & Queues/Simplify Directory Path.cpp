string Solution::simplifyPath(string path)
{
  stack<string> s;
  s.push("/");

  for (int i = 1; i < path.length(); i++)
  {
    string str = "";
    while (path[i] != '/' && i < path.length())
    {
      str += path[i];
      i++;
    }

    if (str == ".." && s.size() > 1)
    {
      s.pop();
      s.pop();
    }

    if (str != ".." && str != "." && str != "")
    {
      s.push(str);
      s.push("/");
    }
  }

  stack<string> stemp;

  while (!s.empty())
  {
    stemp.push(s.top());
    s.pop();
  }

  string res = "";
  while (!stemp.empty())
  {
    res += stemp.top();
    stemp.pop();
  }

  int n = res.length() - 1;
  if (res.length() > 1)
    res.erase(res.begin() + n);

  return res;
};