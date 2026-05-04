1class Solution {
2   
3    public static class Pair {
4        public String key;
5        public Double value;
6
7        public Pair(String a, Double b) {
8            this.key = a;
9            this.value = b;
10        };
11    }
12
13    public double dfs(Map<String, List<Pair>> adj, String src, String dst, double prod, Set<String> vis) {
14        if (!adj.containsKey(src) || !adj.containsKey(dst))
15            return -1.0;
16
17        if (src.equals(dst))
18            return prod;
19
20        vis.add(src);
21
22        for (Pair nei : adj.get(src)) {
23            if (!vis.contains(nei.key)) {
24                double res = dfs(adj, nei.key, dst, prod * nei.value, vis);
25                if (res != -1.0)
26                    return res;
27            }
28        }
29        return -1.0;
30    }
31
32    public double[] calcEquation(List<List<String>> eq, double[] val, List<List<String>> qry) {
33        int n = eq.size();
34        Map<String, List<Pair>> adj = new HashMap<>();
35
36        for (int i = 0; i < n; i++) {
37            String num = eq.get(i).get(0);
38            String deno = eq.get(i).get(1);
39
40            adj.computeIfAbsent(num, k -> new ArrayList<>()).add(new Pair(deno, val[i]));
41            adj.computeIfAbsent(deno, k -> new ArrayList<>()).add(new Pair(num, 1.0 / val[i]));
42        }
43
44        double[] resp = new double[qry.size()];
45        for (int i = 0; i < qry.size(); i++) {
46            String num = qry.get(i).get(0);
47            String deno = qry.get(i).get(1);
48            resp[i] = dfs(adj, num, deno, 1.0, new HashSet<String>());
49        }
50
51        return resp;
52    }
53}