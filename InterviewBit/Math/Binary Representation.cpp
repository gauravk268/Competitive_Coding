string Solution::findDigitsInBinary(int A) {
    if(A==0)    return "0";

    string result="";
    while(A){
        if(A&1) result+= "1";
        else result += "0";

        A>>=1;
    }

    reverse(result.begin(), result.end());
    return result;
}
