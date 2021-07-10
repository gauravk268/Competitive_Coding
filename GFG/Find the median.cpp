class Solution
{
public:
	int find_median(vector<int> v)
	{
		sort(v.begin(), v.end());

		int k = v.size();
		if (k & 1)
		{
			return v[k / 2];
		}
		else
		{
			return (v[k / 2] + v[k / 2 - 1]) / 2;
		}

		return 0;
	}
};