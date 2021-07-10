int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  priority_queue<int> q;
  
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          q.push(mat[i][j]);
          if(q.size() > k)  q.pop();
      }
  }
  
  return q.top();
}