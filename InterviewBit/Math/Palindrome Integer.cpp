int Solution::isPalindrome(int A) {
    string s = to_string(A);
    int first=0,last = s.size()-1;
    while(first<last){
        if(s[first]!=s[last]) return 0;
        first++;
        last--;
    }
    return 1;
}
