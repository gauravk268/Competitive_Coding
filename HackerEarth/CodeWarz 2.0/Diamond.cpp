#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
    int N, K, i;
    cin>>N>>K;

    int arr[N], diff[N], max=0, min=60000, maxIndex, minIndex;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        if(max<arr[i]){
            max = arr[i];
            maxIndex = i;
        }
        if(min>arr[i]){
            min = arr[i];
            minIndex = i;
        }
    }

    ll result=0;
    if(minIndex<maxIndex)
        result = (max-min) * K;
    else result = 0;

    if(N==1){
        result = 0;
    }

    cout<<result<<endl;
}