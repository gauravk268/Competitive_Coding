1class Solution {
2    int[] dx = new int[] { 0, 0, 1, -1 };
3    int[] dy = new int[] { 1, -1, 0, 0 };
4
5    private boolean isValid(int a, int b, int n, int m) {
6        return (a >= 0 && b >= 0 && a < n && b < m);
7    }
8
9    public int orangesRotting(int[][] g) {
10        int n = g.length, m = g[0].length;
11        Queue<int[]> q = new LinkedList<>();
12
13        for (int i = 0; i < n; i++) {
14            for (int j = 0; j < m; j++) {
15                if (g[i][j] == 2) {
16                    q.add(new int[] { i, j, 0 });
17                }
18            }
19        }
20
21        int res = 0;
22        while (!q.isEmpty()) {
23            int[] curr = q.poll();
24
25            for (int i = 0; i < 4; i++) {
26                int ax = dx[i] + curr[0];
27                int ay = dy[i] + curr[1];
28
29                if (isValid(ax, ay, n, m) && g[ax][ay] == 1) {
30                    q.add(new int[] { ax, ay, curr[2] + 1 });
31                    g[ax][ay] = 2;
32                    res = Math.max(res, curr[2] + 1);
33                }
34            }
35        }
36
37        for (int i = 0; i < n; i++) {
38            for (int j = 0; j < m; j++) {
39                if (g[i][j] == 1)
40                    return -1;
41            }
42        }
43
44        return res;
45    }
46}