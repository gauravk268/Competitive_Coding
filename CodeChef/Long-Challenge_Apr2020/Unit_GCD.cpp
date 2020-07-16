#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll N, numDays=0;
    cin>>N;

    if( N<=3){
        numDays = 1;
    }
    else{
        numDays = N/2;
    }

    cout<<numDays<<"\n";

    switch(N){
        case 1:
            cout<<"1 1\n";
            break;
        case 2:
            cout<<"2 1 2\n";
            break;
        case 3:
            cout<<"3 1 2 3\n";
            break;

        default:
            ll day=2;
            cout<<"3 1 2 3\n";

            for(int i=4; i<=N; i+=2){
                if(i==N){
                    cout<<"1 "<<i<<"\n";
                }
                else{
                    cout<<"2 "<<i<<" "<<i+1<<"\n";
                }
            }

    }
}

int main() {
    int testCases;
    cin>>testCases;
    
    while(testCases--){
        solve();
    }
    
	return 0;
}