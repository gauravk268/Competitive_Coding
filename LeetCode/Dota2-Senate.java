1class Solution {
2    public String predictPartyVictory(String senate) {
3        Queue<Integer> rQueue = new LinkedList<>();
4        Queue<Integer> dQueue = new LinkedList<>();
5        int n=senate.length();
6        
7        for(int i=0; i<senate.length(); i++){
8            if(senate.charAt(i) == 'R') rQueue.add(i);
9            else dQueue.add(i);
10        }
11
12        while(!rQueue.isEmpty() && !dQueue.isEmpty()){
13            int dIndex = dQueue.poll();
14            int rIndex = rQueue.poll();
15
16            if(dIndex < rIndex){
17                dQueue.add(dIndex+n);
18            }
19            else{
20                rQueue.add(rIndex+n);
21            }
22        }
23
24        if(rQueue.isEmpty())
25            return "Dire";
26        return "Radiant";
27    }
28}