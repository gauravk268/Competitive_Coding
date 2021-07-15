class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        queue<vector<string>> paths;

        unordered_set<string> dict={wordList.begin(), wordList.end()};
        dict.insert(endWord);

        paths.push({beginWord});
        int level=1;
        int minLevel=INT_MAX;

        unordered_set<string> visited;
        while(paths.size()){
          vector<string> path=paths.front();  paths.pop();
          if(path.size() > level){
            for(string w:visited) dict.erase(w);
            visited.clear();
            if(paths.size()>minLevel) break;
            else level=path.size();
          }

          string last=path.back();
          for(int i=0; i<last.size(); i++){
            string news=last;
            for(char c='a'; c<='z'; c++){
              news[i]=c;
              if(dict.find(news)!=dict.end()){
                vector<string> newPath=path;
                newPath.push_back(news);
                visited.insert(news);
                if(news==endWord){
                  minLevel=level;
                  result.push_back(newPath);
                }else{
                  paths.push(newPath);
                }
              }
            }
          }

        }

        return result;
    }
};