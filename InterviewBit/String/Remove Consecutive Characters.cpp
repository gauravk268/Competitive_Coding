string Solution::solve(string A, int B) {
    string result="";
    if(B==1)    return result;
    
    int temp[A.length()];
    bool flag=false;
    char last='.';
    for(int i=0; i<A.length(); i++){
        if(last=='.' || last!=A[i]){
            temp[i]=0;
        }else{
            temp[i]=temp[i-1]+1;
        }
        
        
        if(temp[i]+1>=B)  flag=true;
        last=A[i];
    }
    
    if(!flag)   return A;
    else{
        for(int i=A.length()-1; i>=0; i--){
            if(temp[i]+1>=B){
                i-=(temp[i]);
            }else{
                result+=A[i];
            }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}
