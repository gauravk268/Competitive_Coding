class Solution {
    public boolean searchMatrix(int[][] mat, int target) {
        int m = mat.length, n = mat[0].length;

        int i = 0, j = m - 1, mid = (j - i) / 2;
        while (i <= j) {
            mid = i + (j - i) / 2;

            if (target >= mat[mid][0] && target <= mat[mid][n - 1]) {
                break;
            } else if (target < mat[mid][0]) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        int row = mid;
        i = 0;
        j = n - 1;
        int l = 5;
        while (i <= j && l >= 0) {
            l--;
            mid = i + (j - i) / 2;

            int k = mat[row][mid];
            if (k == target) {
                return true;
            } else if (k > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return false;
    }
}