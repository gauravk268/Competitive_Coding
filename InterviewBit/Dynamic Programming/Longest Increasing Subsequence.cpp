int Solution::lis(const vector<int> &A) {
    int n=A.size();
    if(n<2)    return n;
    
    int LIS[n];
    for(int i=0; i<n; i++){
        LIS[i]=1;
        for(int j=0; j<i; j++)
            if(A[j]<A[i] && LIS[i]<1+LIS[j]){
                LIS[i]=max(LIS[i], 1+LIS[j]);
            }
    }

    return *max_element(LIS, LIS+n);
}