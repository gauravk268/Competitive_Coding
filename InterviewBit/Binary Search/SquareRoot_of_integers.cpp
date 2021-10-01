int Solution::sqrt(int A) {
    
    if(A<=0)
    return 0;
    
    // if(A <=3)
    // return 1;
    
    int start = 1;
    int end = A;
    
    int mid;
    int ans;
    
    while(start<=end)
    {
        mid = end-(end-start)/2;
        
        if(mid == A/mid)
        {
            return mid;
        }
        
        if(mid < A/mid)
        {
            start = mid+1;
            
        }
        else
        {
            end = mid-1;
            ans = mid-1;
        }
    }
    
    return ans;
}

