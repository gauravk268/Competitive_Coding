# https://leetcode.com/problems/sort-array-by-parity-ii/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
       int n=nums.size();int j=0;
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
         for(int i=0;i<n;i=i+2)
        {
             nums[i]=even[j];
             nums[i+1]=odd[j];
             j++;
            
        }
        return nums;
        
    }
};