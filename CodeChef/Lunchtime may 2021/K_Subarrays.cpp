#include <bits/stdc++.h>
using namespace std;
#define FAST        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int         long long int
#define yes         cout<<"YES"<<endl 
#define no          cout<<"NO"<<endl

int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
 
/* Driver program to test maxSubArraySum */

int32_t main(){FAST;
    int T = 1;cin >> T;
    while(T--) {
        int n,ans=0,k;  cin>>n>>k;       int a[n];   for(int i=0;i<n;i++)cin>>a[i];
        int siz = sizeof(a)/sizeof(a[0]);
      cout<<maxSubArraySum(a, siz)<<'\n';
   
          
    }
    return 0;
}