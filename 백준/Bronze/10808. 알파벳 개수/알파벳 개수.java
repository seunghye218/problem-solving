import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] arr = new int[128];
        
        String word = scanner.nextLine();
        for (char c: word.toCharArray()) {
            arr[c]++;
        }
        
        StringBuilder s = new StringBuilder();
        for (char c = 'a'; c <= 'z'; ++c) {
            s.append(arr[c]);
            s.append(' ');
        }
        s.delete(s.length() - 1, s.length());
        System.out.println(s);
    }
}
