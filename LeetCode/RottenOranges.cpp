class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         if(grid.empty())
        return 0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        int r=grid.size();
        int c=grid[0].size();
        
        queue<pair<int,int>>q;
        int mins=0,tot=0,count=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]!=0)
                tot++;
            }
        }
        
        while(!q.empty()){
            int k=q.size();
            count+=k;
            while(k--){
                int n1=q.front().first;
                int n2=q.front().second;
                
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nn1=n1+dx[i];
                    int nn2=n2+dy[i];
                    if(nn1<0 || nn1>=r || nn2<0 || nn2>=c || grid[nn1][nn2]!=1)
                    continue;
                    
                    
                    grid[nn1][nn2]=2;
                    q.push({nn1,nn2});
                }
            }
            if(!q.empty())mins++;
        }
        if(tot==count)
        return mins;
        else
        return -1;
    }
};
