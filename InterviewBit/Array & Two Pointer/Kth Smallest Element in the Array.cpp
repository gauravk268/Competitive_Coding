int Solution::kthsmallest(const vector<int> &A, int k) {
  priority_queue<int> pq;

  for(int i=0; i<A.size(); i++){
    pq.push(A[i]);

    while(pq.size() && pq.size() > k)  pq.pop();
  }

  return pq.top();
}
