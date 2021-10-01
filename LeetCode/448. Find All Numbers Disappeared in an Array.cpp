class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,int>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            res[nums[i]]++;
        }
        vector<int>temp;
        for(auto i:res)
        {
            temp.push_back(i.first);
        }
       // return temp;
        int max=INT_MIN;
        int min=INT_MAX;
        vector<int>ans;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]>max)
                max=temp[i];
            if(temp[i]<min)
                min=temp[i];
        }
        int j=0;
        for(int i=1;i<min;i++)
        {
            ans.push_back(i);
        }
        for(int i=min;i<=max;)
        {
            if(temp[j]!=i)
            {
                ans.push_back(i);
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        for(int i=max+1;i<=nums.size();i++)
        {
            ans.push_back(i);
        }
        return ans;
       /* map<int,int>res1;
        for(int i=0;i<ans.size();i++)
        {
            res1[ans[i]]++;
        }
        vector<int>ans1;
        for(auto i:res1)
        {
            ans1.push_back(i.first);
        }
        return ans1;*/
    }
};
