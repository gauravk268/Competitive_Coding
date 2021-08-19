class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) 
    {
        int n=mat.size(), m=mat[0].size();
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j])
                {
                    mat[i][j] += mat[i-1][j];
                }
            }
        }
        
        int result=0;
        for(int i=0; i<n; i++)
        {
            sort(mat[i].begin(), mat[i].end());
            
            for(int j=0; j<m; j++)
            {
                result = max(result, mat[i][j]*(m-j));
            }
        }
        
        return result;
    }
};