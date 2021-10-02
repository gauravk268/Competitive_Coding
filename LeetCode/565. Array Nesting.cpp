# https://leetcode.com/problems/array-nesting/

class Solution {
public:
    int arrayNesting(vector<int>& a) {
        int maxl = 0;
        for(int i = 0; i < a.size(); i++)
        {
            int size = 0;
            for(int j = i ; a[j] >= 0; size++) 
            {
                int aj = a[j] ;
                a[j] = -1 ; // mark a[j] as visited;
                j = aj;
            }
            maxl = max(maxl, size);
        }

        return maxl;
    }
};
