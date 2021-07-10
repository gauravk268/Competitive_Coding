int Solution::isPower(int A) {
    if(A==1)    return 1;
    
    for(int i=2; i*i<=A; i++){
        float k=log(A)/log(i);
        if(floor(k)==k) return 1;
    }
    
    return 0;
}
