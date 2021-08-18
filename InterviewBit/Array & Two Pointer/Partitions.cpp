int Solution::solve(int n, vector<int> &B) {
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += B[i];
    }

    if(sum%3)   return 0;

    int count[n], k=B[n-1], d=sum/3;
    
    if(B[n-1]==d)   count[n-1]=1;
    else count[n-1]=0;

    for(int i=n-2; i>=0; i--)
    {
        k+=B[i];

        if(k==d)
        {
            count[i]=1+count[i+1];
        }
        else
        {
            count[i]=count[i+1];
        }
    }

    int result=0, dk=0;
    for(int i=0; i<n-2; i++)
    {
        dk+=B[i];

        if(dk==d)
        {
            result += count[i+2];
        }
    }

    return result;
}
