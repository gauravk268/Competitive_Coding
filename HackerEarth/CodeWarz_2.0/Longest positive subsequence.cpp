#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int testCases;
    cin>>testCases;
    
    while(testCases--){
        int N, i, count=0;
        cin>>N;
        
        ll arr[N], sum=0;

        for(i=0; i<N; i++){
            cin>>arr[i];
            sum+=arr[i];
        }

        sort(arr, arr+N, greater<int>());

        if(sum>0)
            count = N;
        else if(arr[0] <= 0)
            count=0;
        else{
            for(i=0; i<N; i++){
                sum+=arr[i];
                count++;
                if((sum+arr[i+1] <= 0))
                    break;
            }
        }

        cout<<count<<endl;
    }
}