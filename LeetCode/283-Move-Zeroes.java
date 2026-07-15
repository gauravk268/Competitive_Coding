class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                while (j < n && nums[j] == 0) {
                    j++;
                }

                if (j < n && nums[j] != 0) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                }
            }
        }
    }
}