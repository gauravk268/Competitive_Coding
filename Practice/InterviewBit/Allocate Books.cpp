bool isValid(vector<int> &A, int num, int maxPage){
    int temp=1, sum=0;
    for(auto x:A){
        if(x>maxPage)   return false;
        
        if(sum+x > maxPage){
            sum=x;
            temp++;
        }else{
            sum += x;
        }
        
        if(temp>num)    return false;
    }
    
    return true;
}

int Solution::books(vector<int> &A, int B) {
    if(B > A.size())    return -1;
    
    int low= A[0], high=0, result=INT_MAX;
    for(auto x:A)   high+=x;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(isValid(A, B, mid)){
            result=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    
    return result;
}
