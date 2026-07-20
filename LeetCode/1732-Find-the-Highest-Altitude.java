class Solution {
    public int largestAltitude(int[] gain) {
        int res=0, temp=0;

        for(int i=0; i<gain.length; i++){
            temp += gain[i];
            res = Math.max(res, temp);
        }

        return res;
    }
}