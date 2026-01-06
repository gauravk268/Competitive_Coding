1class Solution {
2    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
3        Set<Integer> s1 = new HashSet<>(), s2 = new HashSet<>();
4
5        for (int i : nums1)
6            s1.add(i);
7        for (int i : nums2)
8            s2.add(i);
9
10        List<Integer> a = new ArrayList<>(), b = new ArrayList<>();
11        s1.forEach(i -> {
12            if (!s2.contains(i)) {
13                a.add(i);
14            }
15        });
16        s2.forEach(i -> {
17            if (!s1.contains(i)) {
18                b.add(i);
19            }
20        });
21
22        return List.of(a, b);
23    }
24}