1class Solution {
2    Map<Integer, Integer> mem = new HashMap<>();
3
4    public int tribonacci(int n) {
5        if (n == 0)
6            return 0;
7        if (n == 1 || n == 2)
8            return 1;
9
10        if (mem.containsKey(n))
11            return mem.get(n);
12        Integer res = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
13        mem.put(n, res);
14
15        return res;
16    }
17}