class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> mp = new HashMap();

        for (int i = 0; i < arr.length; i++) {
            mp.put(arr[i], mp.getOrDefault(arr[i], 0) + 1);
        }

        Set<Integer> st = new HashSet<>();
        for(Integer i:mp.values()){
            if(!st.add(i)){
                return false;
            }
        }

        return true;
    }
}