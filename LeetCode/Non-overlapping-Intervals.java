1class Solution {
2    public int eraseOverlapIntervals(int[][] intervals) {
3        Arrays.sort(intervals, (a, b)->Integer.compare(a[0], b[0]));
4
5        int res=1;
6        int[] prev = intervals[0];
7        for(int i=1; i<intervals.length; i++){
8            int[] curr = intervals[i];
9            if(curr[0] >= prev[1]){
10                res++;
11                prev=curr;
12            }
13            else if(curr[1] < prev[1]){
14                prev = curr;
15            }
16        }
17
18        return intervals.length-res;
19    }
20}
21