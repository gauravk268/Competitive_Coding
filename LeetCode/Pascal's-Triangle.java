class Solution {
    public List<List<Integer>> generate(int n) {
        if (n == 0)
            return new ArrayList<>();

        List<List<Integer>> resp = new ArrayList<>();
        resp.add(List.of(1));
        if (n == 1)
            return resp;

        List<Integer> curr = new ArrayList<>();
        int i = 1;
        while (i != n) {
            i++;

            curr = new ArrayList<>();
            List<Integer> prev = resp.get(resp.size() - 1);

            for (int j = 0; j < i; j++) {
                Integer value = 0;
                if (j == 0)
                    value = prev.get(j);
                else if (j == prev.size())
                    value = prev.get(j - 1);
                else
                    value = prev.get(j) + prev.get(j-1);
                curr.add(value);
            }

            resp.add(curr);
        }

        return resp;
    }
}