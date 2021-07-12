int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    int grid[100];
    memset(grid, 0, sizeof(grid));
    
    map<int, int> lad, snk;
    for(auto &x:A){
      grid[x[0]]=1;
      lad[x[0]]=x[1];
    }

    for(auto &x:B){
        grid[x[0]]=2;
        snk[x[0]]=x[1];
    }

    int n=101;
    int step[n];
    for(int i=0; i<n;i++)   step[i]=INT_MAX;
    step[0]=step[1]=0;
    
    for(int i=2; i<=100; i++){
      int g=INT_MAX;
      for(int j=1; j<=6; j++){
        if(i-j >= 1){
          g=min(g, step[i-j]);
        }
      }

      if(g!=INT_MAX){
        if(grid[i]==2){
            grid[i]=3;
            if(step[snk[i]] > g+1){
                step[snk[i]]=g+1;
                i=snk[i];
                continue;
            }
        }else if(grid[i]!=3) step[i]=min(step[i], g+1);
      }
      if(grid[i]==1)  step[ lad[i] ]=step[i];
    }

    // for(int i=0; i<10; i++){
    //     for(int j=1; j<=10; j++){
    //         cout<<step[(10*i)+j]<<" ";
    //     }cout<<endl;
    // }

    return (step[100]==INT_MAX)?-1:step[100];
}
