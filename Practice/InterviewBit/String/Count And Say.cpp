string Solution::countAndSay(int A) {
    if(A==1)    return "1";
    string temp=countAndSay(A-1), result="";
    
    for(int i=0; i<temp.length(); i++){
        int count=1;
        while(i+1<temp.length() && temp[i]==temp[i+1]){
            count++;
            i++;
        }
        
        result += count+'0';
        result += temp[i];
    }
    
    return result;
}
