class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int k=nums.size();
        for(int i=0; i<k; i++)    nums.push_back(nums[i]);
        
        return nums;
    }
};