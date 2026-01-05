1class Solution {
2    public int largestAltitude(int[] g) {
3        int n = g.length, result = Math.max(0, g[0]), tempSum = g[0];
4
5        for (int i = 1; i < n; i++) {
6            tempSum += g[i];
7            result = Math.max(result, tempSum);
8        }
9
10        return result;
11    }
12}