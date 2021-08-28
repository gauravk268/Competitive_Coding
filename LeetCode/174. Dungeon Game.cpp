class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) 
    {
        int n=d.size(), m=d[0].size();
        int arr[n+1][m+1];
        
        for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) arr[i][j]=INT_MAX;
        
        arr[n][m-1]=arr[n-1][m]=1;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                int need = min(arr[i+1][j], arr[i][j+1]) - d[i][j];
                arr[i][j] = (need <= 0) ? 1:need;
            }
        }
        
        return arr[0][0];
    }
};