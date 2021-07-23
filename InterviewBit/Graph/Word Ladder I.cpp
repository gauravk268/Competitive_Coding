int Solution::solve(string A, string B, vector<string> &C) {
    int result=1;
    unordered_set<string> dct(C.begin(), C.end());

    queue<string> q;
    q.push(A);

    while(q.size()){
      int k=q.size();

      while(k--){
        string cur=q.front();
        q.pop();

        if(cur==B)  return result;
        dct.erase(cur);

        for(int i=0; i<cur.length(); i++){
          char tmp=cur[i];

          for(int j=0; j<26; j++){
            cur[i]='a'+j;
            if(dct.find(cur)!=dct.end()){
              q.push(cur);
              dct.erase(cur);
            }
          }
          cur[i]=tmp;
        }
      }
      result++;
    }

    return 0;
}
