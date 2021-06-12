string Solution::longestCommonPrefix(vector<string> &A) {
    sort(A.begin(), A.end(), [](string a, string b){return a.length()<b.length();});
    
    string result=A[0];
    for(int i=1; i<A.size(); i++){
        int k=0;
        while(k<result.length() && result.substr(0, result.length()-k)!=A[i].substr(0, result.length()-k))   k++;
        
        result = result.substr(0, result.length()-k);
    }
    
    return result;
}
