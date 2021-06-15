int minSwap(int *arr, int n, int k) {
    int value=0;
    for(int i=0; i<n; i++)  if(arr[i]<=k)   value++;
    
    int great=0, start=0, end=0;
    while(end<value){
        if(arr[end]>k)    great++;
        end++;
    }
    
    int result=great;
    while(end<n){
        if(arr[end]>k)  great++;
        if(arr[start]>k)    great--;
        
        end++;
        start++;
        
        result = min(result, great);
    }
    
    return result;
}