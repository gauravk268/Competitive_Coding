// https://projecteuler.net/problem=3

#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)
#define pb push_back
#define endl "\n"

const int MOD = 4000000;
const ll MODL = 600851475143;
const int SIZE_INT = 16;

bool isPrime(ll i){
    if(((i-1)%6 == 0 || (i+1)%6 == 0))
        return true;
    return false;
}

void solve()
{
    // vector<ll> value;
    // for(ll i=2; i*i<=MODL; i++){
    //     if(isPrime(i) && MODL%i == 0){
    //         value.pb(i);
    //         value.pb(MODL/i);
    //     }
    //     // cout<<i<<endl;
    // }

    // sort(value.begin(), value.end(), greater<int>());
    

    const long numm = 600851475143;
    long newnumm = numm;
    long largestFact = 0;
    
    int counter = 2;

    while (counter * counter <= newnumm) {
        if (newnumm % counter == 0) {
            newnumm = newnumm / counter;
            largestFact = counter;
        } else {
            counter++;
        }
    }

    if (newnumm > largestFact) { // the remainder is a prime number
        largestFact = newnumm;
    }

    cout<<largestFact<<endl;
}

int main()
{
    //two lines to speed-up
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();

    // int testCases;
    // cin >> testCases;

    // while (testCases--)
    // {
    //     solve();
    // }

    // return 0;
}