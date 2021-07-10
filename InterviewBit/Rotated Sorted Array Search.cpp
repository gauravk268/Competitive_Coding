int findPivot(const vector<int> &A){
    int n=A.size();
    if(A[0]<A[n-1]) return 0;
    
    int low=0, high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int left=(mid-1)%n, right=(mid+1)%n;
        
        if(A[mid]<=A[right] && A[mid]<=A[left])     return mid;
        
        if(A[low]<=A[mid])  low=mid;
        else if(A[mid]<=A[high])    high=mid;
    }
    
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    int n=A.size();
    
    int index=findPivot(A);
    
    if(B>=A[0] && B<=A[index-1]){
        int low=0, high=index-1, result=-1;
    
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(A[mid]==B)   return mid;
            if(A[mid]>B)    high=mid-1;
            else low=mid+1;
        }
    }else if(B>=A[index] && B<=A[n-1]){
        int low=index, high=n-1, result=-1;
    
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(A[mid]==B)   return mid;
            if(A[mid]>B)    high=mid-1;
            else low=mid+1;
        }
    }
    
    return -1;
}
