int Solution::strStr(const string A, const string B) {
    if(A.length()<B.length())  return -1;
    
    
    for(int i=0; i<A.length() && A.length()-i>=B.length(); i++){
        if(A[i]==B[0]){
            int j=1;
            while(j<B.length() && A[i+j]==B[j])     j++;
            
            if(j==B.length())   return i;
        }
    }
    
    return -1;
}
