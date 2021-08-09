// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        if(n<=1)    return arr;
        
        int i=n-2, j=n-1;
        while(i>=0 && arr[i] >= arr[i+1])   i--;
        
        if(i<0){
            sort(arr.begin(), arr.end());
            return arr;
        }
        
        while(j>=0 && arr[j]<=arr[i])   j--;
        
        swap(arr[i], arr[j]);
        reverse(arr.begin()+i+1, arr.end());
        return arr;
    }
};

// 5 2 3 6 1 4

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends