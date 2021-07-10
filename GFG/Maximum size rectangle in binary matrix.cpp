// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends

/*You are required to complete this method*/

int maxHist(int mat[], int n)
{
  stack<int> s;
  int topVal, maxArea = 0, area = 0, i = 0;

  while (i < n)
  {
    if (s.empty() || mat[s.top()] <= mat[i])
    {
      s.push(i++);
    }
    else
    {
      topVal = mat[s.top()];
      s.pop();
      area = topVal * i;
      if (s.size())
        area = topVal * (i - s.top() - 1);
      maxArea = max(maxArea, area);
    }
  }

  while (s.size())
  {
    topVal = mat[s.top()];
    s.pop();
    area = topVal * i;
    if (s.size())
      area = topVal * (i - s.top() - 1);
    maxArea = max(maxArea, area);
  }

  return maxArea;
}

class Solution
{
public:
  int maxArea(int M[MAX][MAX], int n, int m)
  {
    int result = maxHist(M[0], m);

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        if (M[i][j])
          M[i][j] += M[i - 1][j];

      result = max(result, maxHist(M[i], m));
    }

    return result;
  }
};

// { Driver Code Starts.
int main()
{
  int T;
  cin >> T;

  int M[MAX][MAX];

  while (T--)
  {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> M[i][j];
      }
    }
    Solution obj;
    cout << obj.maxArea(M, n, m) << endl;
  }
}
// } Driver Code Ends