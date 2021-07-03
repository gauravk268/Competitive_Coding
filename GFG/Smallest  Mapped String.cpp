// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string mappedString(string S) {
        set<char> key;
        unordered_map<char, char> mp;
        
        for(int i=0; i<S.length(); i++)     key.insert(S[i]);
        
        string result="";
        for(int i=0; i<S.length(); i++){
            if(mp.find(S[i])==mp.end()){
                mp[S[i]]=*key.begin();
                key.erase(key.begin());
                result += mp[S[i]];
            }else{
                result+=mp[S[i]];
            }
        }
        
        return result;
    }
};


// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        Solution obj;
        cout << obj.mappedString(S) << "\n";
    }
}
  // } Driver Code Ends