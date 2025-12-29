1class Solution {
2    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
3        int n=candies.length;
4        Integer maxValue = Arrays.stream(candies).max().getAsInt();
5
6        List<Boolean> result = new ArrayList<>();
7        for(int i=0; i<n; i++){
8            result.add(candies[i] + extraCandies >= maxValue);
9        }
10        
11        return result;
12    }
13}