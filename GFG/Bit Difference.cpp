// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int n, long long int arr[])
    {
        long long result = 0;
        long long count, k;
        for (int i = 0; i < 32; i++){
            count=0;
            k=1<<i;
            
            for (int j = 0; j < n; j++) 
                if(arr[j]&k)    
                    count++;
            
            result += (2 * count * (n-count))%1000000007;
        }
        
        return result%1000000007;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends