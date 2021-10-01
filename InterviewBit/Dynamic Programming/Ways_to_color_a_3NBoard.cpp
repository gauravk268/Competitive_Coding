int Solution::solve(int A) {
    int d3=24,d2=12;
    for(int i=2;i<=A;i++){
        int t1=d3,t2=d2;
        d3=t1*9+t2*10;
        d2=t1*5+t2*7;
    }
    return (d3+d2);
}
