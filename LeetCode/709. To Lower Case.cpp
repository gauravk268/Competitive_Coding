class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.length(); i++){
            if(s[i] >= 'A'-0 && s[i]<='Z'-0){
                s[i]-= 'A'-'a';
            }
        }
        
        return s;
    }
};