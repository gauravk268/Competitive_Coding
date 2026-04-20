import java.util.Scanner;

public class IncreasingArray {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            int n = input.nextInt();
            int arr[] = new int[n];
            arr[0] = input.nextInt();
            long res = 0;

            for (int i = 1; i < n; i++) {
                arr[i] = input.nextInt();

                if (arr[i] <= arr[i - 1]) {
                    res += (arr[i - 1] - arr[i]);
                    arr[i] = arr[i - 1];
                }
            }

            System.out.println(res);
        }
    }
}
