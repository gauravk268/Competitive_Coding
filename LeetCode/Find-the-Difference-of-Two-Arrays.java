1class Solution {
2    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
3        int n = nums1.length, m = nums2.length;
4
5        Map<Integer, Boolean> mp1 = new HashMap<>();
6        Map<Integer, Boolean> mp2 = new HashMap<>();
7
8        for (int i = 0; i < n; i++) {
9            mp1.put(nums1[i], true);
10        }
11
12        for (int i = 0; i < m; i++) {
13            mp2.put(nums2[i], true);
14        }
15
16        List<Integer> a = new ArrayList<>(), b = new ArrayList<>();
17        for (Integer key : mp1.keySet()) {
18            if (!mp2.containsKey(key)) {
19                a.add(key);
20            }
21        }
22
23        for (Integer key : mp2.keySet()) {
24            if (!mp1.containsKey(key)) {
25                b.add(key);
26            }
27        }
28
29        return List.of(a, b);
30    }
31}