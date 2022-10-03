class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> new1;
        for(int i=0;i<=n-1;i++)
        {
            new1.push_back(nums[i]);
            
        }
        vector<int> new2;
        for(int i=n;i<=2*n-1;i++)
        {
            new2.push_back(nums[i]);
            
        }
        vector<int> new3;
        for(int i=0;i<n;i++)
        {
            new3.push_back(new1[i]);
            new3.push_back(new2[i]);
            
        }
        return new3;
    }
};
