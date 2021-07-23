vector<int> fib={1, 1};

int nearestFib(int n){
  if(n<=1)  return n;

  for(int i=0; i<fib.size(); i++){
    if(fib[i]>n)  return fib[i-1];
  }
}

int Solution::fibsum(int A) {
  int a=1, b=1;

  while(a<=A){
    int k=a+b;
    fib.push_back(k);
    a=b;
    b=k;
  }

  int count=0;
  while(A>0){
    int k=nearestFib(A);
    A-=k;
    count++;
  }

  return count;
}
