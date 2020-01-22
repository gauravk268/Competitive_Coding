#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    double S, uX, uY, vX, vY;
    cin>>S>>uX>>uY>>vX>>vY;
    
    int flag =0;

    double time1 = (2*uY)/10;
    double time2 = (2*vY)/10;
    
    double totalTime = S / (uX + vX);
    
    if(totalTime <= time1 && totalTime <=time2){
        double distance1, distance2;
        distance1 = uY * totalTime - 0.5 * 10 * totalTime * totalTime;
        distance2 = vY * totalTime - 0.5 * 10 * totalTime * totalTime;

        if(distance2 == distance1) flag=1;
        else flag = 0;
    }

    else{
        double distance = time1 * uX + time2 * vX;

        if(distance == S) flag=1;
        else flag = 0;
    }
    
    if(flag)
        cout<<"YES\n";
    else 
        cout<<"NO\n";
        
    
    return 0;
}