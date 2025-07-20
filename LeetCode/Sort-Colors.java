class Solution {
    public void sortColors(int[] nums) {
        int n=nums.length;
        int i=0, j=0;

        for(int k=0; k<3; k++){
            while(i<n && nums[i] == k){
                i++;
            }

            j=i;

            while(j<n){
                if(nums[j] == k){
                    nums[j] = nums[i];
                    nums[i] = k;
                    i++;
                }

                j++;
            }
        }
    }
}