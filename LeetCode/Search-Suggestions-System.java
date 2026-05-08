1import java.util.ArrayList;
2import java.util.Arrays;
3import java.util.Collection;
4import java.util.Collections;
5import java.util.List;
6
7class Solution {
8    class Trie {
9        public Trie[] child;
10        public List<String> values;
11
12        public Trie() {
13            this.child = new Trie[26];
14            this.values = new ArrayList<>();
15        }
16
17        public void insert(String word) {
18            Trie curr = this;
19            for (char c : word.toCharArray()) {
20                if (curr.child[c - 'a'] == null) {
21                    curr.child[c - 'a'] = new Trie();
22                }
23                curr = curr.child[c - 'a'];
24                curr.values.add(word);
25                Collections.sort(curr.values);
26                if (curr.values.size() > 3) {
27                    curr.values.remove(curr.values.size() - 1);
28                }
29            }
30        }
31    }
32
33    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
34        Arrays.sort(products);
35        Trie root = new Trie();
36        for (String s : products) {
37            root.insert(s);
38        }
39
40        List<List<String>> result = new ArrayList<>();
41        for (char c : searchWord.toCharArray()) {
42            if (root != null && root.child[c - 'a'] != null) {
43                root = root.child[c - 'a'];
44                result.add(root.values);
45            } else {
46                root = null;
47                result.add(new ArrayList<>());
48            }
49        }
50
51        return result;
52    }
53}
54