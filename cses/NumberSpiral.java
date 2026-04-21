import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NumberSpiral {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());

        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long y = Long.parseLong(st.nextToken());
            long x = Long.parseLong(st.nextToken());

            long maxVal = Math.max(y, x);
            long res = (maxVal - 1) * (maxVal - 1);

            if (maxVal % 2 == 1) {
                if (y == maxVal) {
                    res += x;
                } else {
                    res += maxVal + (maxVal - y);
                }
            } else {
                if (y == maxVal) {
                    res += maxVal + (maxVal - x);
                } else {
                    res += y;
                }
            }

            out.println(res);
        }

        out.flush();
        out.close();
    }
}