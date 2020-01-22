
// C++ program of above approach 
#include<bits/stdc++.h> 
using namespace std; 


int longestPalindromeSubseq(string s) {
       int n = s.length();
        int ans[n][n];
        
//         String of Length 1
        for(int i=0; i<n; i++) ans[i][i] = 1;
        
//         Loop of lengths starting from 2;
        for(int L=2; L<=n; L++){
            for(int i=0; i<n-L+1; i++){
                int j = i+L-1;
                if(s[i] == s[j]){
                    ans[i][j] = (L == 2)  ?  2 : ans[i+1][j-1] + 2;
                }else ans[i][j] = max(ans[i][j-1],ans[i+1][j]);
            }
        }
        return ans[0][n-1];
    } 

/* Driver program to test above functions */
int main() 
{ 
    int n;
    string seq; 
    cin>>n>>seq; 
    int lenn =  longestPalindromeSubseq(seq);
    if(lenn>(n/2)){
        cout<<"YES\n";
       // if(n%2==0){
            
       // }
    }else{
        cout<<"NO\n";
    }
    return 0; 
}
