#include <bits/stdc++.h>
using namespace std;

int dx[8]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8]={0, 0, -1, 1, 1, -1, 1, -1};
int n=0;

bool isValid(int x, int y){
    return (x>=0 && y>=0 && x<n && y<n);
}

int main() {
    int t;  cin>>t;

    while(t--){
        cin>>n;
        if(n==0)    continue;

        int mat[n][n], vis[n][n];
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<n; i++)  for(int j=0; j<n; j++)  cin>>mat[i][j];

        int result=0;
        for(int i=0; i<n; i++)  for(int j=0; j<n; j++){
            queue<pair<int, int>> q;
            if(!vis[i][j] && mat[i][j]){
                result++;
                q.push({i, j});
                while(q.size()){
                    pair<int, int> cur=q.front();   q.pop();
                    vis[i][j]=1;
                    for(int k=0; k<8; k++){
                        pair<int, int> nex={cur.first+dx[k], cur.second+dy[k]};
                        if(isValid(nex.first, nex.second) && mat[nex.first][nex.second] && !vis[nex.first][nex.second]){
                            q.push(nex);
                            vis[nex.first][nex.second]=1;
                        }
                    }
                }
            }
        }

        cout<<result<<"\n";
    }
}
