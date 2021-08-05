const int MOD=1e9+7;

int Solution::solve(int A) {
  long long result = 0, i=0;

  while(1<<i < A)  i++;
  
  if(1<<i == A){
    return (1+(i*(1<<(i-1))))%MOD;
  }else{
    i--;
    result = (i*(1<<(i-1)))%MOD;
    result = (result + (A-(1<<i)+1))%MOD;
    result = (result + solve(A - (1<<i)))%MOD;
  }
  
  return result;
}
