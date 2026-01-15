1class Solution {
2    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
3        int n = rooms.size();
4        boolean[] vis = new boolean[n];
5        Queue<Integer> q = new LinkedList<>();
6
7        q.add(0);
8        vis[0] = true;
9        int res = 1;
10
11        while (!q.isEmpty()) {
12            Integer curr = q.poll();
13            for (Integer key : rooms.get(curr)) {
14                if (!vis[key]) {
15                    vis[key] = true;
16                    q.add(key);
17                    res++;
18                }
19            }
20
21        }
22        return res == n;
23    }
24}