class Solution
{
public:
  int deleteAndEarn(vector<int> &nums)
  {
    int arr[10005] = {0};

    for (int i = 0; i < nums.size(); i++)
    {
      arr[nums[i]] += nums[i];
    }

    int take = 0, skip = 0;
    for (int i = 1; i <= 10000; i++)
    {
      int takei = skip + arr[i];
      int skipi = max(take, skip);

      take = takei;
      skip = skipi;
    }

    return max(take, skip);
  }
};