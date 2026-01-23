1class Solution {
2    public int findCircleNum(int[][] mp) {
3        int n=mp.length;
4        boolean[] vis = new boolean[n];
5        Queue<Integer> q = new LinkedList<>();
6
7        int res=0;
8        for(int i=0; i<n; i++){
9            if(!vis[i]){
10                q.add(i);
11                res++;
12
13                while(!q.isEmpty()){
14                    int curr = q.poll();
15
16                    for(int j=0; j<n; j++){
17                        if(mp[curr][j] == 1 && !vis[j]){
18                            q.add(j);
19                            vis[j]=true;
20                        }
21                    }
22                }
23            }
24        }
25
26        return res;
27    }
28}