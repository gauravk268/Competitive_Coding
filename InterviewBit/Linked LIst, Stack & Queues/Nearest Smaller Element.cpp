vector<int> Solution::prevSmaller(vector<int> &A) {
  int n=A.size();
  vector<int> result={-1};
  stack<int> s;
  s.push(0);

  for(int i=1; i<n; i++){
    while(s.size() && A[s.top()]>=A[i]) s.pop();

    if(s.size())  result.push_back(A[s.top()]);
    else result.push_back(-1);

    s.push(i);
  }

  return result;
}
