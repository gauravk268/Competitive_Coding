int fun(vector<int>&A , int mid)
{
    int count=1;
    int sum=0;
    
    int i=0;
    int n = A.size();
    
    while(i<n)
    {
        sum += A[i];
        
        if(sum > mid)
        {
            count++;
            sum=A[i];
        }
        
        i++;
    }
    
    return count;
}



int Solution::books(vector<int> &A, int B) {
    
    if(A.size() < B)
    return -1;
    
    int start = *max_element(A.begin(),A.end());
    
    int end =0;
    for(int x:A)
    {
        end += x;
    }
    
    int mid;
    int ans;
    
    while(start <= end)
    {
        mid = end-(end-start)/2;
        
        int tmp = fun(A,mid);
        
        // if(tmp == B)
        // {
        //      //ans = max(ans,mid);
        //     return mid;
        // }
        
        if(tmp > B)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
            ans = mid;
        }
        
       
    }
    
    return ans;
}

