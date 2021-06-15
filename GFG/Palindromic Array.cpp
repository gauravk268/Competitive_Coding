int reverseK(int k){
    int result=0;
    while(k){
        result*=10;
        result += k%10;
        k/=10;
    }
    return result;
}

/*Complete the function below*/
int PalinArray(int a[], int n){  
    for(int i=0; i<n; i++){
        if(a[i] != reverseK(a[i]))  return 0;
    }
    
    return 1;
}