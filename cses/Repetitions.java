import java.util.Scanner;

public class Repetitions {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            String val = input.nextLine();

            if (val.length() == 0) {
                System.out.println(0);
                return;
            }

            int res = 1, tempRes = 1;
            char prevChar = val.charAt(0);

            for (int i = 1; i < val.length(); i++) {
                if (val.charAt(i) == prevChar) {
                    tempRes++;
                } else {
                    res = Math.max(tempRes, res);
                    tempRes = 1;
                    prevChar = val.charAt(i);
                }
            }

            res = Math.max(res, tempRes);

            System.out.println(res);
        }
    }
}
