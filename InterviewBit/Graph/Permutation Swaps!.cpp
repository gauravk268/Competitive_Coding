int ds[100001];

int find(int x){
    if(ds[x]==-1)return x;
    return ds[x]=find(ds[x]);
}

void Union(int x,int y){
    ds[x]=y;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int>> &C) {
    memset(ds,-1,sizeof(ds));
    for(auto i:C){
        int x=A[i[0]-1];
        int y=A[i[1]-1];
        if(find(x)!=find(y))
        Union(find(x),find(y));
    }
    
    for(int i=0;i<A.size();i++){
        if(A[i]!=B[i]){
            if(find(A[i])!=find(B[i]))  return false;
        }
    }
    return true;
}