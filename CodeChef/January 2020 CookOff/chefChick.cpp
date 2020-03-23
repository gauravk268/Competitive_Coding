#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, i, result;
        cin>>N;
        
        int arr[N];
        for(i=0; i<N; i++)
            cin>>arr[i];
        
        sort(arr, arr+N);

        result = arr[0];
        
        cout<<result<<"\n";
    }
    
    return 0;
}