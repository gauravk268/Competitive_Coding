vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> result;
    set<int> k;
    k.insert(A);
    k.insert(B);
    k.insert(C);

    int count=0;
    while(count<D){
        int n=*k.begin();
        result.push_back(n);

        k.insert(n*A);
        k.insert(n*B);
        k.insert(n*C);
        k.erase(k.begin());

        count++;
    }

    return result;
}
  