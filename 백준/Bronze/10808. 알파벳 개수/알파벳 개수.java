import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String str = scanner.nextLine();

        int[] arr = new int[128];

        for (char c : str.toCharArray()) {
            ++arr[c];
        }

        StringBuilder out = new StringBuilder();
        for (byte c = 'a'; c <= 'z'; ++c) {
            out.append(arr[c]);
            out.append(' ');
        }

        System.out.println(out);
    }
}
