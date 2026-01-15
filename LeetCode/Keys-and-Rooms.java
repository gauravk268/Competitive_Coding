1class Solution {
2    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
3        int n = rooms.size();
4        int[] vis = new int[n];
5
6        for (int i = 0; i < n; i++) {
7            vis[i] = 0;
8        }
9
10        Queue<Integer> q = new LinkedList<>();
11        for (Integer key : rooms.getFirst()) {
12            q.add(key);
13        }
14        vis[0] = 1;
15
16        while (!q.isEmpty()) {
17            Integer curr = q.poll();
18            vis[curr] = 1;
19
20            for (Integer key : rooms.get(curr)) {
21                if(vis[key] == 0)
22                    q.add(key);
23            }
24        }
25
26        for (int i = 0; i < n; i++) {
27            if (vis[i] == 0)
28                return false;
29        }
30
31        return true;
32    }
33}