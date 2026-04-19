import java.util.Scanner;

public class MissingNumber {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            long n = input.nextLong();
            long actualSum = (n * (n + 1)) / 2;

            for (long i = 0; i < n - 1; i++) {
                actualSum -= input.nextLong();
            }
            
            System.out.println(actualSum);
        }

    }
}
