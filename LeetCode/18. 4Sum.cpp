class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> res;
    if (nums.size() == 0)
      return res;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int k = j + 1, l = n - 1;
        while (k < l)
        {
          int t1 = nums[i] + nums[j] + nums[k] + nums[l];

          if (t1 < target)
          {
            k++;
          }
          else if (t1 > target)
          {
            l--;
          }
          else
          {
            res.push_back({nums[i], nums[j], nums[k], nums[l]});

            int t1 = nums[k], t2 = nums[j];
            while (k < l && nums[k] == t1)
              k++;
            while (k < l && nums[l] == t2)
              l--;
          }
        }
        while (j + 1 < n && nums[j] == nums[j + 1])
          j++;
      }
      while (i + 1 < n && nums[i] == nums[i + 1])
        i++;
    }

    return res;
  }
};