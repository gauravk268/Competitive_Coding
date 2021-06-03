#include<bits/stdc++.h>
using namespace std;

class FenwickTree{
  int *base, n;

  public:
    FenwickTree(int value[], int n){
      this->n=n;
      base = new int[n+1];
      memset(base, 0, sizeof(base));

      for(int i=0; i<n; i++){
        base[i+1]+=value[i];

        int k=(i+1)+((i+1)&(-(i+1)));
        while(k<n+1){
          base[k]+=value[i];
          k=k+(k&(-k));
        }
      }
    }

    ~FenwickTree(){
      delete base;
    }

    void update(int value, int index){
      int diff = value-base[index];
      base[index+1]+=diff;

      int k=(index+1)+((index+1)&(-(index+1)));
      while(k<n+1){
        base[k]+=diff;
        k=k+(k&(-k));
      }
    }

    int getSum(int index){
      int result=base[index+1];

      int k=(index+1)-((index+1)&(-(index+1)));
      while(k<n+1){
        result += base[k];
        k=k+(k&(-k));
      }
    }
};