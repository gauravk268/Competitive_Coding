int par[100005];

bool comp(vector<int> &a, vector<int> &b){
  return a[2]<b[2];
}

void merge(int a, int b){
  par[a]=b;
  return;
}

int find(int &a){
  if (par[a] == -1) return a;
  return par[a] = find(par[a]);
}

int Solution::solve(int A, vector<vector<int> > &B){
  memset(par, -1, sizeof(par));

  sort(B.begin(), B.end(), comp);
  int cost=0;

  for(auto &x:B){
    int a=find(x[0]);
    int b=find(x[1]);

    if(a!=b){
      cost+=x[2];
      merge(a, b);
    }
  }

  return cost;
}
