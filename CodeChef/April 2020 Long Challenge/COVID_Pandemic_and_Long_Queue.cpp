#include <iostream>
using namespace std;

void solve(){
    int N;
    cin>>N;
    
    int count=0, flag=0;
    int arr[] = {0, 0, 0, 0, 0, 0};
    
    for(int i=0; i<N; i++){
        
        arr[5] = arr[4];
        arr[4] = arr[3];
        arr[3] = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
        
        cin>>arr[0];
        
        count = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5];
        if(count>1 && count<=6){
            flag=1;
            break;
        }
    }
    
    if(flag)    cout<<"NO\n";
    else cout<<"YES\n";
    
}

int main() {
    int testCases;
    cin>>testCases;
    
    while(testCases--){
        solve();
    }
    
	return 0;
}