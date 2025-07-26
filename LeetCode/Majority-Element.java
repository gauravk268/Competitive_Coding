class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        int el=nums[0], cnt=1;

        for(int i=1; i<n; i++){
            if(el == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }

            if(cnt == 0){
                el = nums[i];
                cnt=1;
            }
        }

        return el;
    }
}