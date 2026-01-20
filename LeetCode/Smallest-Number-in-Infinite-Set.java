1class SmallestInfiniteSet {
2    int num=1;
3    private Queue<Integer> q;
4    private Set<Integer> s;
5
6    public SmallestInfiniteSet() {
7        q = new PriorityQueue<>();
8        s = new HashSet<>();
9        num=1;
10    }
11    
12    public int popSmallest() {
13        if(!q.isEmpty() && q.peek() < num){
14            int val=q.poll();
15            s.remove(val);
16            return val;
17        }
18
19        return num++;
20    }
21    
22    public void addBack(int val) {
23        if(val < num && s.add(val)){
24            q.add(val);
25        }
26    }
27}
28
29/**
30 * Your SmallestInfiniteSet object will be instantiated and called as such:
31 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
32 * int param_1 = obj.popSmallest();
33 * obj.addBack(num);
34 */