bool isVowel(char a){
    return (a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
}

const int MOD=1e9+7;
int Solution::solve(string A) {
    int n=A.length();
    int cons=0, vow=0, ans=0;
    
    for(int i=0; i<n; i++){
        if(isVowel(A[i])){
            vow++;
            ans=(ans+cons)%MOD;
        }else{
            cons++;
            ans=(ans+vow)%MOD;
        }
    }
    
    return ans%MOD;
}
