class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int s=nums.size();
        int ans=0;
        for(int i=0;i<s;i++)
        {
            for(int j=i+1;j<s;j++)
            {
                if(nums[i]==nums[j])
                    ans++;
            }
        }
        return ans;
    }
};
