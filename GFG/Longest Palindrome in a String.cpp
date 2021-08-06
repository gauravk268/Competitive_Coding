// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution {
  public:
    bool isPalin(string s){
        int i=0, j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        
        return true;
    }

    string longestPalin (string S) {
        int n=S.length(), resLen=1;
        string result=S.substr(0, 1);
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int k=j-i+1;
                string temp = S.substr(i, k);
                if(S[i]==S[j] && isPalin(temp) && resLen<k){
                    result = temp;
                    resLen = k;
                }
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends