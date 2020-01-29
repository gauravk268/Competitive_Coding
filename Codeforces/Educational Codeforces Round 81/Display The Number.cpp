#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int even(int n){
    if(n % 2 == 0)
        return 1;
    else
        return 0;
}

int main() {
    int T, i;
    cin>>T;
    while(T--){
        int n;
        cin>>n;

        if(n){
            if(even(n)){
                while(true){
                    cout<<1;
                    n-=2;
                    if(n == 0)
                        break;
                }
            }
            else{
                cout<<7;
                n-=3;
                if(n){
                    while(true){
                        cout<<1;
                        n-=2;
                        if(n == 0)
                            break;
                    }
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}