1class Solution {
2    private boolean[] vis;
3    private HashMap<Integer, List<int[]>> mp = new HashMap<>();
4    int res;
5
6    private void dfs(int k) {
7        vis[k] = true;
8
9        if (!mp.containsKey(k))
10            return;
11
12        List<int[]> nei = mp.get(k);
13        for (int[] el : nei) {
14            int nextEl = el[0], dir = el[1];
15            if (!vis[nextEl]) {
16                res += dir;
17                dfs(nextEl);
18            }
19        }
20    }
21
22    public int minReorder(int n, int[][] con) {
23        vis = new boolean[n + 1];
24        res = 0;
25
26        for (int[] val : con) {
27            int u = val[0], v = val[1];
28            mp.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[] { v, 1 });
29            mp.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[] { u, 0 });
30        }
31
32        dfs(0);
33        return res;
34    }
35}