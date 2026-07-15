class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;

        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
        }

        while (i < n) {
            nums[i++] = 0;
        }
    }
}