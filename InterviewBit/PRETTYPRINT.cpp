vector<vector<int> > Solution::prettyPrint(int A) {
    int n=2*A-1;
    int x=A-1, y=A-1;
    vector<vector<int>> result(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result[i][j] = 1+max(abs(x-i), abs(y-j));
        }
    }
    
    return result;
}