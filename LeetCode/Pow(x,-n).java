class Solution {
    public double myPow(double x, int n) {
        boolean flag = false;
        if (n < 0)
            flag = true;

        double resp = 1;
        if (flag == false) {
            while (n != 0) {
                if (n % 2 == 0) {
                    x = x * x;
                    n = n / 2;
                } else {
                    n--;
                    resp = resp * x;
                }
            }
        } else {
            while (n != 0) {
                if (n % 2 == 0) {
                    x = x * x;
                    n = n / 2;
                } else {
                    n++;
                    resp = resp * x;
                }
            }
        }

        if(flag)
            return 1/resp;
        return resp;
    }
}