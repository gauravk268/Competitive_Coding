int Solution::solve(vector<vector<int> > &A) {
  int n=A.size(), m=A[0].size();
  if(!n || !m)  return 0;

  for(int i=1; i<n; i++){
    for(int j=0; j<m; j++){
      if(A[i][j]==1)  A[i][j] = A[i][j] + A[i-1][j];
      else A[i][j]=0;
    }
  }    

  for(int i=0; i<n; i++)  sort(A[i].begin(), A[i].end(), greater<int>());
  int result=0;

  for(int i=0; i<n; i++){
    int k=0;
    for(int j=0; j<m; j++){
      k=A[i][j]*(j+1);
      result=max(result, k);
    }
  }

  return result;
}
