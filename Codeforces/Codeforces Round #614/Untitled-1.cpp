/*

A.R.C. Markland-N is a tall building with n floors numbered from 1 to n

. Between each two adjacent floors in the building, there is a staircase connecting them.

It's lunchtime for our sensei Colin "ConneR" Neumann Jr, and he's planning for a location to enjoy his meal.

ConneR's office is at floor s
of the building. On each floor (including floor s, of course), there is a restaurant offering meals. However, due to renovations being in progress, k

of the restaurants are currently closed, and as a result, ConneR can't enjoy his lunch there.

CooneR wants to reach a restaurant as quickly as possible to save time. What is the minimum number of staircases he needs to walk to reach a closest currently open restaurant.

Please answer him quickly, and you might earn his praise and even enjoy the lunch with him in the elegant Neumanns' way!
Input

The first line contains one integer t
(1≤t≤1000) — the number of test cases in the test. Then the descriptions of t

test cases follow.

The first line of a test case contains three integers n
, s and k (2≤n≤109, 1≤s≤n, 1≤k≤min(n−1,1000)

) — respectively the number of floors of A.R.C. Markland-N, the floor where ConneR is in, and the number of closed restaurants.

The second line of a test case contains k
distinct integers a1,a2,…,ak (1≤ai≤n

) — the floor numbers of the currently closed restaurants.

It is guaranteed that the sum of k
over all test cases does not exceed 1000

.
Output

For each test case print a single integer — the minimum number of staircases required for ConneR to walk from the floor s

to a floor with an open restaurant.
Example
Input
Copy

5
5 2 3
1 2 3
4 3 3
4 1 2
10 2 6
1 2 3 4 5 7
2 1 1
2
100 76 8
76 75 36 67 41 74 10 77

Output
Copy

2
0
4
0
2

*/










#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        long long int numFloor, posConner, result=0;
        int numClosedRest, i, j, flag=0, result1, result2, mark;
        cin>>numFloor>>posConner>>numClosedRest;
        
        long long int arr[numClosedRest];
        
        for(i=0; i<numClosedRest; i++){
            cin>>arr[i];
            arr[i] = abs(arr[i] - posConner);

            if(arr[i] == posConner)
                flag=1;
        }    
            
        if(flag == 0){      //if restaurant of conner floor is open
            result = 0;
        }

        else{
            sort(arr, arr+numClosedRest);
            result = arr[0];
        }
        
        cout<<result<<"\n";
        
    }
}