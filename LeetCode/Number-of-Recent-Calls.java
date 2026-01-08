1class RecentCounter {
2    Queue<Integer> q;
3
4    public RecentCounter() {
5        q = new PriorityQueue<Integer>();
6    }
7    
8    public int ping(int t) {
9        q.add(t);
10        while(!q.isEmpty() && q.peek() < t-3000){
11            q.remove();
12        }
13
14        return q.size();
15    }
16}
17
18/**
19 * Your RecentCounter object will be instantiated and called as such:
20 * RecentCounter obj = new RecentCounter();
21 * int param_1 = obj.ping(t);
22 */