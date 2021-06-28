// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    int dx[4]={0, 0, -1, 1};
    int dy[4]={-1, 1, 0, 0};
    char dir[4]={'L', 'R', 'U', 'D'};
    int N=0;
    vector<string> result;
    
    public:
    bool isValid(int x, int y, vector<vector<int>> &m, vector<vector<int>> &vis){
        return (x>=0 && y>=0 && x<N && y<N && m[x][y]==1 && !vis[x][y]);
    }
    
    void helper(vector<vector<int>> &m, int x, int y, string res, vector<vector<int>> vis){
        if(x==N-1 && y==N-1){
            result.push_back(res);
            return;
        }
        
        for(int i=0; i<4; i++){
            if(isValid(x+dx[i], y+dy[i], m, vis)){
                vis[x+dx[i]][y+dy[i]]=1;
                helper(m, x+dx[i], y+dy[i], res+dir[i], vis);
                vis[x+dx[i]][y+dy[i]]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        N=n;
        
        if(m[0][0]==0)    return result;
        
        vector<vector<int>> vis(n, vector<int> (n));
        for(int i=0; i<n; i++)  for(int j=0; j<n; j++)  vis[i][j]=0;
        
        vis[0][0]=1;
        helper(m, 0, 0, "", vis);
        sort(result.begin(), result.end());
        return result;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends