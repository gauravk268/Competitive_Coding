string Solution::simplifyPath(string A)
{
  stack<string> s;

  string tmp = "";
  for (int i = 0; i < A.length(); i++)
  {
    if (A[i] == '/')
    {
      if (tmp == "..")
      {
        if (s.size())
        {
          s.pop();
        }
      }
      else if(tmp!="" && tmp!=".")
        s.push(tmp);

      tmp = "";
    }
    else
    {
      tmp += A[i];
    }
  }

  if (tmp == "..")
  {
    if (s.size())
    {
      s.pop();
    }
  }else if (tmp != "." && tmp != "")
    s.push(tmp);

  string result = "";
  while (s.size())
  {
    result = "/" + s.top() + result;
    s.pop();
  }

  if (result.length() == 0)
    return "/";
    
  return result;
}
