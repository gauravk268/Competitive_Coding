#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long subArraySum(ll ea[], int n, int sum){
    unordered_map<int, int> mapSum;
    ll res=0;
    int csum=0;
    for(int i=0; i<n; i++){
        csum += ea[i];

        if(csum == sum)     res++;

        if(mapSum.find(csum-sum) != mapSum.end())
            res += mapSum[csum-sum];

        mapSum[csum]++;
    }

    return res;
}

void solve(){
    ll N;
    cin>>N;
    
    ll A[N];
    memset(A, 0, sizeof(A[0])*N);

    for(int i=0; i<N; i++){
        cin>>A[i];
        
        if(A[i]<0)      A[i] *= -1;

        if(A[i]%4 == 0)
            A[i] = 2;
        else if(A[i]%2 == 1)
            A[i] = 0;
        else 
            A[i] = 1;
    }

    ll totalSubArrays = (N * (N+1))/2;

    ll invalidSubArrays = subArraySum(A, N, 1);

    cout<<totalSubArrays - invalidSubArrays<<"\n";
}

int main() {
    int testCases;
    cin>>testCases;
    
    while(testCases--){
        solve();
    }
    
	return 0;
}