class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int result=1;
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);

        while(q.size()){
          int n=q.size();
          while(n--){
            string cur = q.front();
            q.pop();
            if(cur==endWord)  return result;
            dict.erase(cur);

            for(int i=0; i<cur.length(); i++){
              char t1=cur[i];
              for(int j=0; j<26; j++){
                cur[i] = 'a'+j;
                if(dict.find(cur)!=dict.end()){
                  q.push(cur);
                }
              }
              cur[i]=t1;
            }
          }
          result++;
        }
        
        return 0;
    }
};