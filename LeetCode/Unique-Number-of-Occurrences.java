1class Solution {
2    public boolean uniqueOccurrences(int[] arr) {
3        Map<Integer, Integer> mp = new HashMap<>();
4
5        for (int i : arr) {
6            mp.put(i, mp.getOrDefault(i, 0) + 1);
7        }
8
9        Set<Integer> s = new HashSet<>();
10        for (Integer i : mp.values()) {
11            if (!s.add(i)) {
12                return false;
13            }
14        }
15
16        return true;
17    }
18}