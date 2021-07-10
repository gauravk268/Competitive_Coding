class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        if(*max_element(arr, arr+n) > x)    return 1;
        
        int start=0, end=0, len=n, sum=0;
        while(end<n){
            while(sum<=x && end<n)  sum += arr[end++];
            
            while(sum>x && start<n){
                len = min(len, end-start);
                sum-=arr[start++];
            }
        }
        
        return len;
    }
};