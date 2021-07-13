#include<bits/stdc++.h>
using namespace std;

class edge{
  public:
    int a, b, w;
};

edge parent[10001], arr[10001];

bool comp(edge a, edge b){
  return a.w < b.w;
}

int find(int &a){
  if (par[a] == -1) return a;
  return par[a] = find(par[a]);
}

void union(int a, int b){
  par[a]=b;
}

int main(){
  memset(par, -1, sizeof(par));

  int n, m;
  cin>>n>>m;

  for(int i=1; i<=m; i++){
    cin>>arr[i].a>>arr[i].b>>arr[i].w;
  }

  sort(arr, arr+m, comp);

  int cost=0;
  for(int i=1; i<=m; i++){
    int a=find(arr[i].a);
    int b=find(arr[i].b);

    if(a!=b){
      cost += arr[i].w;
      union(a, b);
    }
  }

  cout<<cost<<endl;
  return 0;
}