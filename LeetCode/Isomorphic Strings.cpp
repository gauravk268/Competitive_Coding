class Solution {
public:
    bool isIsomorphic(string s, string t) {
      if(s.length() != t.length())  return false;

      map<char, char> replace, revReplace;

      for(int i=0; i<s.length(); i++){
        if(replace.find(s[i])==replace.end() && revReplace.find(t[i])==revReplace.end())  replace[ s[i]]=t[i], revReplace[t[i]]=s[i];
        else if(replace[s[i]] != t[i] || revReplace[t[i]]!=s[i])  return false;
      }

      return true;
    }
};