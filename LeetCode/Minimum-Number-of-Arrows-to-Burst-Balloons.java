1class Solution {
2    public int findMinArrowShots(int[][] points) {
3        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
4
5        int res = 1;
6        int last = points[0][1];
7
8        for (int i = 1; i < points.length; i++) {
9            if (points[i][0] > last) {
10                last = points[i][1];
11                res++;
12            }
13        }
14
15        return res;
16    }
17}
18