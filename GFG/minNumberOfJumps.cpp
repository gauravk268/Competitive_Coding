#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int minJumps(int arr[], int n){
        int maxreach=arr[0],steps=1,jumps=0;
        for(int i=0;i<n;i++){
            maxreach=max(maxreach,arr[i]+i);
            steps-=1;
            if(i==n-1)return jumps;
            if(steps==0){
                jumps+=1;
                steps=maxreach-i;
                if(i>=maxreach)return -1;
            }
        }
        return -1;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i,j;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr,n)<<endl;    
    }
    return 0;
}