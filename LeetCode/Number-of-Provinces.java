1class Solution {
2    public int findCircleNum(int[][] mp) {
3        int n=mp.length;
4        boolean[] vis = new boolean[n];
5
6        int res=0;
7        for(int i=0; i<n; i++){
8            if(!vis[i]){
9                vis[i]=true;
10                res++;
11                Queue<Integer> q = new LinkedList<>();
12                q.add(i);
13
14                while(!q.isEmpty()){
15                    int curr = q.poll();
16
17                    for(int j=0; j<n; j++){
18                        if(mp[curr][j] == 1 && !vis[j]){
19                            q.add(j);
20                            vis[j]=true;
21                        }
22                    }
23                }
24            }
25        }
26
27        return res;
28    }
29}