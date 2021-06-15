#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;  cin>>t;

    while(t--)
    {
        long long n, k;   cin>>n>>k;
        vector<long long> value(n);

        k%=n;

        for(long long i=0; i<n; i++)
            cin>>value[i];
        
        vector<long long> temp(n);
        for(long long i=0; i<n; i++)
        {
            long long t = (n-k+i)%n;
            temp[i] = value[t];
        }

        for(long long i=0; i<n; i++)
            cout<<temp[i]<<" ";
        cout<<"\n";
    }

    return 0;
}

/*

Sample Input
1
5 2
1 2 3 4 5
Sample Output
4 5 1 2 3

*/