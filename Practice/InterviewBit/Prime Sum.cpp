vector<int> Solution::primesum(int n) {
    bool a[n+1];
    a[0]=a[1]=false;
    
    for(int i=2; i<=n; i++)     a[i]=true;
    for(int i=2; i*i<=n; i++){
        if(a[i]){
            for(int j=i*i; j<=n; j+=i){
                a[j]=false;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(a[i] && a[n-i])  return {i, n-i};
    }
    
    return {-1, -1};
}