class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int s1=jewels.size();
        int s2=stones.size();
        int ans=0;
        for(int i=0;i<s1;i++)
        {
            for(int j=0;j<s2;j++)
            {
                if(jewels[i]==stones[j])
                    ans++;
            }
        }
        return ans;
    }
};
