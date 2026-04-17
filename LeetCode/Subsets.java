1class Solution {
2    public List<List<Integer>> subsets(int[] nums) {
3        List<List<Integer>> resp = new ArrayList<>();
4        resp.add(new ArrayList<>());
5
6        for(int n:nums){
7            int k=resp.size();
8            for(int i=0; i<k; i++){
9                List<Integer> subset = new ArrayList<>(resp.get(i));
10                subset.add(n);
11                resp.add(subset);
12            }
13        }
14
15        return resp;
16    }
17}