class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int n=candies.length;

        int maxVal=0;
        for(int i=0; i<n; i++){
            maxVal = Math.max(candies[i], maxVal);
        }

        List<Boolean> resp = new ArrayList<>();
        for(int i=0; i<n; i++){
            resp.add((candies[i] + extraCandies)>=maxVal);
        }
        return resp;
    }
}