int Solution::solve(int row, int col) {
    return (min(8-row, 8-col) + min(row-1, 8-col) + min(8-row, col-1) + min(row-1, col-1));
}