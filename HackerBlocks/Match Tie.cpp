#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  pair<int, int> a[n];
  for (int i = 0; i < n; i++)   cin >> a[i].first >> a[i].second;

  if (n == 1 || n == 0){
    cout << 1;
    return 0;
  }
  sort(a, a + n);

  int lis[n];
  lis[0] = 1;
  for (int i = 1; i < n; i++)
  {
    lis[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if (a[i].second >= a[j].second)
        lis[i] = max(lis[i], lis[j]+1);
    }
  }

  cout << *max_element(lis, lis+n)<<"\n";
  return 0;
}