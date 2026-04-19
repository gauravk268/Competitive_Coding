import java.util.Scanner;

public class WeirdAlgorithm {

    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            long n = input.nextLong();
            
            System.out.print(n + " ");
            while (n > 1) {
                if ((n & 1) == 0) {
                    n = n / 2;
                } else {
                    n = (n * 3) + 1;
                }

                System.out.print(n + " ");
            }
        }
    }
}