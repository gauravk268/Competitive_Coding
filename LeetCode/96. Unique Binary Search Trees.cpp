class Solution {
public:
    int numTrees(int n) {
        int result=0;
        if(n<3)   return n;
        
        for(int i=1; i<=n; i++)
        {
            int left = numTrees(i-1);
            int right = numTrees(max(0, n-i));
            
            if(left==0)     result += right;
            else if(right==0)   result += left;
            else result += left*right;
        }
        
        return result;
    }
};