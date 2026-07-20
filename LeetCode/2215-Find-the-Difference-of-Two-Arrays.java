class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;

        Map<String, Boolean> mp = new HashMap<>();

        int i = 0, j = 0;
        while (i < n || j < m) {
            if (i < n)
                mp.put("0_" + Integer.toString(nums1[i++]), true);
            if (j < m)
                mp.put("1_" + Integer.toString(nums2[j++]), true);
        }

        List<Integer> res1 = new ArrayList<>();
        List<Integer> res2 = new ArrayList<>();

        i = 0;
        j = 0;
        while (i < n || j < m) {
            if (i < n && !mp.containsKey("1_" + Integer.toString(nums1[i]))) {
                mp.put("1_" + Integer.toString(nums1[i]), true);
                res1.add(nums1[i]);
            }

            if (j < m && !mp.containsKey("0_" + Integer.toString(nums2[j]))) {
                mp.put("0_" + Integer.toString(nums2[j]), true);
                res2.add(nums2[j]);
            }

            i++;
            j++;
        }

        return List.of(res1, res2);
    }
}