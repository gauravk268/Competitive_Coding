int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n=A.size();
    if(n<2)    return n;
    
    int LIS[n], LDS[n];
    for(int i=0; i<n; i++){
        LIS[i]=1;
        LDS[i]=1;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[j]<A[i]){
                LIS[i]=max(LIS[i], 1+LIS[j]);
            }
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(A[j]<A[i]){
                LDS[i] = max(LDS[i], 1 + LDS[j]);
            }
        }
    }

    int result=0;
    for(int i=0; i<n; i++){
        result = max(result, LDS[i]+LIS[i]-1);
    }

    return result;
}
