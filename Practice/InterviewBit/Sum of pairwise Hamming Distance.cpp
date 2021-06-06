int Solution::hammingDistance(const vector<int> &arr) {
    long long n = arr.size();
    long long result = 0;
    
    int count, k;
    for (int i = 0; i < 32; i++){
        count=0;
        k=1<<i;
        
        for (int j = 0; j < n; j++) 
            if(arr[j]&k)    
                count++;
        
        result += 2 * count * (n-count);
    }
    
    return result%1000000007;
}