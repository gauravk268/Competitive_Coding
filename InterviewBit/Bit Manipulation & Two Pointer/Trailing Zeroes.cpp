int Solution::solve(int A) {
    int count=0;
    while(A && !(A&1)){
        count++;
        A>>=1;
    }

    return count;
}
