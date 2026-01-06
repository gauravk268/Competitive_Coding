1class Solution {
2    public int equalPairs(int[][] g) {
3        int n = g.length;
4
5        Map<List<Integer>, Integer> mp = new HashMap<>(), mp1 = new HashMap<>();
6        for (int i = 0; i < n; i++) {
7            List<Integer> temp = new ArrayList<>(), temp1 = new ArrayList<>();
8            for (int j = 0; j < n; j++) {
9                temp.add(g[i][j]);
10                temp1.add(g[j][i]);
11            }
12            mp.put(temp, mp.getOrDefault(temp, 0) + 1);
13            mp1.put(temp1, mp1.getOrDefault(temp1, 0) + 1);
14        }
15
16        int result = 0;
17        for (List<Integer> key : mp.keySet()) {
18            if (mp1.containsKey(key)) {
19                result += (mp1.get(key) * mp.get(key));
20            }
21        }
22
23        return result;
24    }
25}