class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        
        int s=candies.size();
        vector<bool> v(s);
        for(int i=0;i<s;i++)
        {
            if(candies[i]+extraCandies> *max_element(candies.begin(), candies.end())-1)
                v[i]=true;
            else
                v[i]=false;
        }
        return v;
    }
};
