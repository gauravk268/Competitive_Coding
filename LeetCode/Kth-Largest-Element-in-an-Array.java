1class Solution {
2    public int findKthLargest(int[] nums, int k) {
3        int n=nums.length;
4        Queue<Integer> q = new PriorityQueue<>();
5
6        for(Integer i:nums){
7            q.add(i);
8        }
9
10        while(q.size() != k)    q.poll();
11
12        return q.poll();
13    }
14}