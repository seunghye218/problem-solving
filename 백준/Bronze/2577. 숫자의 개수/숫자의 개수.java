import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] arr = new int[128];

        int A = scanner.nextInt(), B = scanner.nextInt(), C = scanner.nextInt();
        int mul = A * B * C;

        String mulDigit = String.valueOf(mul);

        for (char c : mulDigit.toCharArray()) {
            arr[c]++;
        }

        StringBuilder s = new StringBuilder();
        for (char c = '0'; c <= '9'; ++c) {
            s.append(arr[c]);
            s.append('\n');
        }
        System.out.println(s);
    }
}
