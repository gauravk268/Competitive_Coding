

int Solution::pow(int x, int n, int d) {
    
     if (n == 0)
    return  1%d ;

long long res = pow(x , n / 2 , d);
if (n % 2)
    return ((res%d * res%d * x%d) +d)%d ;
else
    return (res%d * res%d + d)%d ;
    
}

