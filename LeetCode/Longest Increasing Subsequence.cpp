class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            auto it=lower_bound(result.begin(), result.end(), nums[i]);
            if(it==result.end())    result.push_back(nums[i]);
            else    *it=nums[i];
        }
        return result.size();
    }
};