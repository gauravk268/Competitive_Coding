int Solution::pow(int x, int n, int d) {
    if(d==1)    return 0;
    if(x==0)    return 0;
    
    long long result=1, base=x;
    while(n){
        if(n&1){
            result = (result*base)%d;
            n--;
        }else{
            n>>=1;
            base = (base*base)%d;
        }
    }
    
    if(result<0)    result = (d-abs(result))%d;
    else   result%=d;
    
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
