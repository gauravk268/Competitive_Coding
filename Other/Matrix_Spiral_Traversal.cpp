#include <iostream>
#include<string>
using namespace std;

#define ll long long
#define mod 1000000007
#define FOR(i, a) for (int i = 0; i < a; i++)
#define FoR(i, a, b) for (int i = a; i < b; i++)
#define MEM(a, n) memset(a, n, sizeof(a[0]) * n)
#define R 5
#define C 5

void printSpiral(int m, int n, int arr[R][C])
{
    int i = 0, k = 0, l = 0;

    while (k < m && l < n)
    {
        for (i = l; i < n; i++)
        {
            cout << arr[k][i] << " ";
        }
        k++;

        for (i = k; i < m; i++)
        {
            cout << arr[i][n - 1] << " ";
        }
        n--;

        for (i = n - 1; i >= l; --i)
        {
            cout << arr[m - 1][i] << " ";
        }
        m--;

        for (i = m - 1; i >= k; --i)
        {
            cout << arr[i][l] << " ";
        }
        l++;
    }
}

void solve()
{
    int arr[R][C] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    printSpiral(R, C, arr);
}

int main()
{
    solve();

    // int testCases;
    // cin>>testCases;

    // while(testCases--){
    //     solve();
    // }

    return 0;
}