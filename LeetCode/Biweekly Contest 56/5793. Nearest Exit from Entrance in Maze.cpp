class Solution {
public:
    int m, n;
    bool isExit(int x, int y){
        return (x==0 || y==0 || x==m-1 || y==n-1);
    }

    bool isValid(int x, int y){
        return (x>=0 && y>=0 && x<m && y<n);
    }

    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m=maze.size();
        n=maze[0].size();
        
        int result=0;
        queue<pair<int, int>> q;
        bool vis[m][n];
        int dis[m][n];
        memset(vis, false, sizeof(vis));
        memset(dis, 0, sizeof(dis));

        q.push({entrance[0], entrance[1]});
        dis[entrance[0]][entrance[1]]=0;

        while(!q.empty()){
            pair<int, int> curr=q.front();
            q.pop();

            vis[curr.first][curr.second]=true;

            for(int i=0; i<4; i++){
                int x=curr.first+dx[i];
                int y=curr.second+dy[i];

                if(isValid(x, y) && maze[x][y]=='.' && !vis[x][y]){
                    dis[x][y]=1+dis[curr.first][curr.second];

                    if(isExit(x, y))    return dis[x][y];

                    vis[x][y]=true;
                    q.push({x, y});
                }
            }
            result++;
        }

        return -1;
    }
};