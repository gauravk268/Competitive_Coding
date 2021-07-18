class Solution {
public:
    int canBeTypedWords(string t, string b) {
      set<char> k;
      for(int i=0; i<b.length(); i++) k.insert(b[i]);
      
      vector<string> words;
      string tmp="";
      
      for(int i=0; i<t.length(); i++){
        if(t[i]==' '){
          words.push_back(tmp);
          tmp="";
        }else{
          tmp+=t[i];
        }
      }
      words.push_back(tmp);
      
      int count=0;
      for(auto &x:words){
        for(int i=0; i<x.length(); i++){
          if(k.find(x[i])!=k.end()){
            count++;
            break;
          }
        }
      }
      
      return words.size()-count;
    }
};