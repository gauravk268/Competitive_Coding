#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, i;
    cin>>T;
    while(T--){
        long long int N, a, b, c, distA, distB;
        cin>>N>>a>>b>>c;
        
        long long int arr[N];
        
        int i, j, flag;
        for(i=0; i<N; i++){
            cin>>arr[i];
            distA = abs(arr[i] - a);
            distB = abs(arr[i] - b);
            arr[i] = distA + distB + c;
        }
            
        sort(arr, arr+N);
        
        cout<<arr[0]<<"\n";
            
    }
    return 0;
}