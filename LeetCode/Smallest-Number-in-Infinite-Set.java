1class SmallestInfiniteSet {
2    private Queue<Integer> q;
3
4    public SmallestInfiniteSet() {
5        q = new PriorityQueue<>();
6        for(int i=1; i<=1000; i++){
7            q.add(i);
8        }
9    }
10    
11    public int popSmallest() {
12        return q.poll();
13    }
14    
15    public void addBack(int num) {
16        if(!q.contains(num))
17            q.add(num);
18    }
19}
20
21/**
22 * Your SmallestInfiniteSet object will be instantiated and called as such:
23 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
24 * int param_1 = obj.popSmallest();
25 * obj.addBack(num);
26 */