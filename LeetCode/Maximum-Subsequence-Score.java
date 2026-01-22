1class Solution {
2    public long maxScore(int[] nums1, int[] nums2, int k) {
3        int n=nums1.length;
4
5        int[][] pairs = new int[n][2];
6        for(int i=0; i<n; i++){
7            pairs[i] = new int[]{nums2[i], nums1[i]};
8        }
9
10        Arrays.sort(pairs, (a, b)->b[0]-a[0]);
11
12        long result=0, currSum=0;
13        Queue<Integer> q = new PriorityQueue<>();
14        
15        for(int i=0; i<n; i++){
16            currSum += pairs[i][1];
17            q.add(pairs[i][1]);
18
19            if(q.size() == k){
20                result = Math.max(result, currSum * pairs[i][0]);
21                currSum -= q.poll();
22            }
23        }
24        
25        return result;
26    }
27}