#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long int N;
    cin>>N;
    
    long long int sum=0;
    int arr[N];
    memset(arr, 0, N);
    
    for(int i=0; i<N; i++)
        cin>>arr[i];
        
    sort(arr, arr+N, greater<int>());
    
    
    for(int i=0; i<N; i++){
        if(arr[i] == 0 || arr[i]<i)
            break;
        
        sum += (arr[i]-i);
    }
    
    sum %= 1000000007;
    
    cout<<sum<<"\n";
    
}

int main() {
    int testCases;
    cin>>testCases;
    
    while(testCases--){
        solve();
    }
    
	return 0;
}