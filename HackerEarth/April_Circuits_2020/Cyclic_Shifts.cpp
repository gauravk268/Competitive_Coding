/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <string.h>
#include <bitset>
using namespace std;

#define ll long long
#define mod 1000000007
#define SIZE_INT 16

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 15; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    cout << "\n";
}

void solve()
{
    uint16_t N, result;
    int m;
    char c;
    cin >> N >> m >> c;
    // N=7881;
    // m = 5;
    // c = 'L';

    if (c == 'L')
        result = (N << m) | (N >> (SIZE_INT - m));

    else if (c == 'R')
        result = (N >> m) | (N << (SIZE_INT - m));

    cout << result << "\n";
}

int main()
{
    //solve();

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        solve();
    }
    return 0;
}