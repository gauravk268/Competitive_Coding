1class Solution {
2    int[] dx = { 1, 0, -1, 0 };
3    int[] dy = { 0, 1, 0, -1 };
4
5    private boolean isValid(int a, int b, int n, int m) {
6        return (a >= 0 && b >= 0 && a < n && b < m);
7    }
8
9    public int nearestExit(char[][] maze, int[] e) {
10        int n = maze.length, m = maze[0].length;
11        boolean[][] vis = new boolean[n][m];
12        Queue<int[]> q = new LinkedList<>();
13
14        q.add(new int[] { e[0], e[1], 0 });
15        vis[e[0]][e[1]] = true;
16        int res = 0;
17        while (!q.isEmpty()) {
18            int[] curr = q.poll();
19            for (int i = 0; i < 4; i++) {
20                int ax = dx[i] + curr[0];
21                int ay = dy[i] + curr[1];
22
23                if (isValid(ax, ay, n, m) && !vis[ax][ay] && maze[ax][ay] == '.') {
24                    q.add(new int[] { ax, ay, curr[2] + 1 });
25                    vis[ax][ay] = true;
26
27                    if (ax == 0 || ay == 0 || ax == n - 1 || ay == m - 1) {
28                        return curr[2] + 1;
29                    }
30                }
31            }
32        }
33
34        return -1;
35    }
36}