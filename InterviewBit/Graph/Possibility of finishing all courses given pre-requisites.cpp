int Solution::solve(int A, vector<int> &B, vector<int> &C) {
  vector<int> ar[A+1], in(A+1, 0);

  for(int i=0; i<B.size(); i++){
    ar[B[i]].push_back(C[i]);
    in[C[i]]++;
  }

  queue<int> q;

  for(int i=1; i<=A; i++)
    if(in[i]==0)  q.push(i);

  vector<int> result;
  while(q.size()){
    int cur=q.front();
    result.push_back(cur);
    q.pop();

    for(int child:ar[cur]){
      in[child]--;
      if(in[child]==0)  q.push(child);
    }
  }

  return (result.size()==A);
}
