1class Solution {
2    public int equalPairs(int[][] grid) {
3        int n = grid.length;
4
5        Map<String, Integer> mp = new HashMap<>();
6        for (int[] a : grid) {
7            StringBuilder sb = new StringBuilder();
8            for (int b : a) {
9                sb.append(b).append(",");
10            }
11            String val = sb.toString();
12            mp.put(val, mp.getOrDefault(val, 0) + 1);
13        }
14
15        int result = 0;
16        for (int i = 0; i < n; i++) {
17            StringBuilder sb = new StringBuilder();
18            for (int j = 0; j < n; j++) {
19                sb.append(grid[j][i]).append(",");
20            }
21            result += mp.getOrDefault(sb.toString(), 0);
22        }
23
24        return result;
25    }
26}