class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        map<char, string> mp;
        for(char i='a'; i<='z'; i++)
        {
            mp[i] = morse[i-'a'];
        }
        
        set<string> ms;
        for(auto &x:words)
        {
            string tmp="";
            for(int i=0; i<x.length(); i++)
            {
                tmp += mp[ x[i] ];
            }
            ms.insert(tmp);
        }
        
        return ms.size();
    }
};