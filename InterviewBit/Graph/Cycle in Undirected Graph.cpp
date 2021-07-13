int par[300005];

void merge(int a, int b){
  par[b]=a;
}

int find(int a){
  if(par[a]==-1)  return a;
  return par[a]=find(par[a]);
}

int Solution::solve(int A, vector<vector<int> > &B) {
  memset(par, -1, sizeof(par));

  for(int i=0; i<B.size(); i++){
    int a=find(B[i][0]);
    int b=find(B[i][1]);

    if(a==b)  return 1;
    else{
      merge(a, b);
    }
  }

  return 0;
}
