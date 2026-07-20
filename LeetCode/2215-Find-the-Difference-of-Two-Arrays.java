class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;

        int[] mp1 = new int[2002], mp2 = new int[2002];

        int i = 0, j = 0;
        while (i < n || j < m) {
            if (i < n) {
                mp1[(nums1[i] >= 0) ? nums1[i] : 1000 + Math.abs(nums1[i])] = 1;
                i++;
            }
            if (j < m) {
                mp2[(nums2[j] >= 0) ? nums2[j] : 1000 + Math.abs(nums2[j])] = 1;
                j++;
            }
        }

        List<Integer> res1 = new ArrayList<>(), res2 = new ArrayList<>();
        i = 0;
        j = 0;
        while (i < n || j < m) {
            if (i < n) {
                if (mp2[(nums1[i] >= 0) ? nums1[i] : 1000 + Math.abs(nums1[i])] != 1) {
                    res1.add(nums1[i]);
                    mp2[(nums1[i] >= 0) ? nums1[i] : 1000 + Math.abs(nums1[i])] = 1;
                }
                i++;
            }

            if (j < m) {
                if (mp1[(nums2[j] >= 0) ? nums2[j] : 1000 + Math.abs(nums2[j])] != 1) {
                    res2.add(nums2[j]);
                    mp1[(nums2[j] >= 0) ? nums2[j] : 1000 + Math.abs(nums2[j])] = 1;
                }
                j++;
            }
        }

        return List.of(res1, res2);
    }
}