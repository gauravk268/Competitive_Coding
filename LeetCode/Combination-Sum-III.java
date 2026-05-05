1class Solution {
2    List<List<Integer>> resp;
3
4    public List<List<Integer>> combinationSum3(int k, int n) {
5        resp = new ArrayList<>();
6        helper(k, n, new ArrayList<>(), 0);
7        return resp;
8    }
9
10    public void helper(int k, int n, List<Integer> res, int i) {
11        if (k == 0 && n == 0) {
12            resp.add(res);
13            return;
14        }
15        if (k <= 0 || n <= 0)
16            return;
17
18        for (int j = i + 1; j < 10; j++) {
19            if (j <= n) {
20                List<Integer> temp = new ArrayList<>(res);
21                temp.add(j);
22                helper(k - 1, n - j, temp, j);
23            }
24        }
25    }
26}
27