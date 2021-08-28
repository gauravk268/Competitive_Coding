class Solution
{
public:
  int binary(vector<vector<int>> &jobs, int i)
  {
    int low = 0, high = i - 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (jobs[mid][0] <= jobs[i][1])
      {
        if (jobs[mid + 1][0] <= jobs[i][1])
          low = mid + 1;
        else
          return mid;
      }
      else
        high = mid - 1;
    }

    return -1;
  }

  int jobScheduling(vector<int> &s, vector<int> &e, vector<int> &p)
  {
    int n = s.size();
    vector<vector<int>> jobs;

    for (int i = 0; i < n; i++)
    {
      jobs.push_back({e[i], s[i], p[i]});
    }

    sort(jobs.begin(), jobs.end());

    int ans[n];
    memset(ans, 0, sizeof(ans));

    ans[0] = jobs[0][2];
    for (int i = 1; i < n; i++)
    {
      int incl = jobs[i][2];
      int index = binary(jobs, i);

      if (index != -1)
        incl += ans[index];

      ans[i] = max(incl, ans[i-1]);
    }

    return ans[n - 1];
  }
};