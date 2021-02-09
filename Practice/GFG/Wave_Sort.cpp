#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define dotl     " "
#define MOD      1000000007
#define deb(x)   cout<<#x<<"="<<x<<endl
#define showRunTime  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);    
// freopen("output.txt", "w", stdout);

#define f  first
#define s  second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void convertToWave(int *arr, int n){
    
    // Your code here
    for(int i=0; i<n; i+=2)
    {
        if(i>0 && arr[i]<arr[i-1])
            swap(&arr[i-1], &arr[i]);

        if(i<n-1 && arr[i]<arr[i+1])
            swap(arr[i], arr[i+1]);
    }
}

int main()
{
	ONLINE_JUDGE;

    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1, n;
    cin >> t;

    while (t--)
    {
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        convertToWave(a, n);

        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    showRunTime;
    return 0;
}

/*
Input 
2
5
1 2 3 4 5
6
2 4 7 8 9 10

Output
2 1 4 3 5
4 2 8 7 10 9
*/