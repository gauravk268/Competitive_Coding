class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            result.push_back(nums[nums[i]]);
        }
        
        return result;
    }
};