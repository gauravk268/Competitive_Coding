bool isVowel(char a){
    a=tolower(a);
    return (a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
}

int Solution::solve(string A) {
    int result=0;
    for(int i=0; i<A.length(); i++){
        if(isVowel(A[i])){
            result+= (A.length()-i);
        }
        result%=10003;
    }
    
    return result;
}
