int Solution::isPalindrome(string A) {
    if(A.length()==1)   return 1;
    int low=0, high=A.length()-1;
    
    while(low<=high){
        while(!isalnum(tolower(A[low])) && low<=high)    low++;
        while(!isalnum(tolower(A[high])) && low<=high)   high--;
        // cout<<low<<" "<<high<<" : ";
        
        if(tolower(A[low])!=tolower(A[high]) && low<=high)   return 0;
        low++;
        high--;
    }   
    
    return 1;
}
