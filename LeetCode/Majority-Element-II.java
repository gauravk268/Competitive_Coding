class Solution {
    public List<Integer> majorityElement(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();

        int n=nums.length;
        for(int i=0; i<n; i++){
            mp.put(nums[i], mp.getOrDefault(nums[i], 0)+1);
        }

        List<Integer> resp = new ArrayList<>();
        for(Integer key:mp.keySet()){
            if(mp.get(key) > n/3){
                resp.add(key);
            }
        }
        return resp;
    }
}