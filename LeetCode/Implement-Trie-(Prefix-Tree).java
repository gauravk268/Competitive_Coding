1class Trie {
2    boolean ends;
3    Map<Character, Trie> child;
4    
5    public Trie() {
6        ends = false;
7        this.child = new HashMap<>();
8    }
9    
10    public void insert(String word) {
11        Trie curr = this;
12        for(char c:word.toCharArray()){
13            if(!curr.child.containsKey(c)){
14                curr.child.put(c, new Trie());
15            }
16            curr = curr.child.get(c);
17        }
18        curr.ends = true;
19    }
20    
21    public boolean search(String word) {
22        Trie curr = this;
23        for(char c:word.toCharArray()){
24            if(!curr.child.containsKey(c)){
25                return false;
26            }
27            curr = curr.child.get(c);
28        }
29
30        return (curr.ends == true);
31    }
32    
33    public boolean startsWith(String prefix) {
34        Trie curr = this;
35        for(char c:prefix.toCharArray()){
36            if(!curr.child.containsKey(c)){
37                return false;
38            }
39            curr = curr.child.get(c);
40        }
41
42        return true;
43    }
44}
45
46/**
47 * Your Trie object will be instantiated and called as such:
48 * Trie obj = new Trie();
49 * obj.insert(word);
50 * boolean param_2 = obj.search(word);
51 * boolean param_3 = obj.startsWith(prefix);
52 */