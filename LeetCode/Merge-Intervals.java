class Solution {
    public int[][] merge(int[][] itr) {
        Arrays.sort(itr, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> resp = new ArrayList<>();
        resp.add(itr[0]);
        for (int i = 1; i < itr.length; i++) {
            int[] temp = resp.get(resp.size() - 1);

            if (temp[1] >= itr[i][0]) {
                resp.getLast()[1] = Math.max(temp[1], itr[i][1]);
            } else {
                resp.add(itr[i]);
            }
        }

        return resp.toArray(new int[resp.size()][]);
    }
}