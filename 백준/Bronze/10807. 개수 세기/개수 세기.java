import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] arr = new int[201];

        int N = scanner.nextInt();
        for (int i = 0 ;i < N; ++i) {
            arr[scanner.nextInt() + 100]++;
        }

        System.out.println(arr[scanner.nextInt() + 100]);
    }
}
