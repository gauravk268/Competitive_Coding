int fun(int mid , vector<int>&C)
{
    long long int count=1;
     long long int sum=0;
    
     long long int i=0;
    
    while(i<C.size())
    {
        sum += C[i];
        if(sum > mid)
        {
            sum=C[i];
            count++;
        }
        i++;
        
    }
    
    return count;
}


int Solution::paint(int A, int B, vector<int> &C) {
    
    long long int mod = 1e7 +3;
    
    long long int start = *max_element(C.begin(),C.end());
    long long int end =0;
    
    
    
    for(long long int x:C)
    {
        end += x;
    }
    
    long long int mid,ans;
    if(C.size()<=A)
    {
        return (start*B)%10000003;
    }
    
    while(start <= end)
    {
        mid = end-(end-start)/2;
        
        long long int tmp = fun(mid,C);
        
        if(tmp > A)
        start = mid+1;
        else
        {
            end = mid-1;
            ans = mid;
        }
        
    }
    
    return (ans*B)%mod;
    
    
}

