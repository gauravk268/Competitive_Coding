class Solution
{
public:
  int fun(vector<int> &w, int days, int k)
  {
    int cnt = 1, tmp = 0;
    for (int i = 0; i < w.size(); i++)
    {
      if (tmp + w[i] > k)
      {
        cnt++;
        tmp = w[i];
      }
      else
      {
        tmp += w[i];
      }
    }

    return cnt;
  }

  int shipWithinDays(vector<int> &w, int days)
  {
    sort(w.begin(), w.end());
    int sum = 0;
    for (auto &x : w)
      sum += x;

    int l = w[w.size() - 1], r = sum, ans = l;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      int k = fun(w, days, mid);

      if (k > days)
      {
        l = mid + 1;
        ans = mid;
      }
      else
      {
        r = mid - 1;
      }
    }

    return ans;
  }
};