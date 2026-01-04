1class Solution {
2    public int maxOperations(int[] nums, int k) {
3        Map<Integer, Integer> mp = new HashMap<>();
4
5        int n = nums.length, res = 0;
6        for (int i = 0; i < n; i++) {
7            if (nums[i] <= k) {
8                int diff = k - nums[i];
9                if (mp.containsKey(diff) && mp.get(diff) > 0) {
10                    res++;
11                    mp.put(diff, mp.get(diff) - 1);
12                } else {
13                    mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
14                }
15            }
16        }
17
18        return res;
19    }
20}