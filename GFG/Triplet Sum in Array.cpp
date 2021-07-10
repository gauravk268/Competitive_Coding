 Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A+n);
        for(int i=0; i<n-2; i++){
            int r=X-A[i], start=i+1, end=n-1;
            while(start < end){
                if(A[start]+A[end] == r){
                    return true;
                }else if(A[start]+A[end] < r){
                    start++;
                }else if(A[start]+A[end] > r){
                    end--;
                }
            }
        }
        
        return false;
    }

};