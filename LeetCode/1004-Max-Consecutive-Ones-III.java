class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int res = 0, j = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (k != 0) {
                    k--;
                } else {
                    while (j < n && nums[j] != 0) {
                        j++;
                    }
                    j++;
                }
            }

            res = Math.max(res, i - j + 1);
        }

        return res;
    }
}