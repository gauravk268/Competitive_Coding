#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
    int T;
    cin>>T;
    while(T--){
        long long int arr[3], n, rem1, rem2;
        int flag = 0;
        cin>>arr[0]>>arr[1]>>arr[2]>>n;
        sort(arr, arr+3);
        
        rem1 = arr[2]-arr[1];
        rem2 = arr[2]-arr[0];
        
        if(n<(rem1+rem2))   flag = 0;
        else
            if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==arr[0])
                if(n%3 == 0)  flag = 1;
                else flag = 0;
            else
                if((arr[0]+arr[1]+arr[2]+n)%3 == 0)
                    flag = 1;
        
        
        if(flag)    cout<<"YES\n";
        else    cout<<"NO\n";
    }
    return 0;
}

