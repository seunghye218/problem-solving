import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
            Deque<Character> deque = new ArrayDeque<>();
        while (scanner.hasNext()) {
            String str = scanner.nextLine();
            if (str.getBytes()[0] == '.') {
                break;
            }
            deque.clear();
            for (char c : str.toCharArray()) {
                if (c != '(' && c != ')' && c != '[' && c != ']') {
                    continue;
                }
                if (c == '(' || c == '[') {
                    deque.push(c);
                    continue;
                }
                if (deque.isEmpty() || (c == ')' && deque.peek() != '(') || (c == ']' && deque.peek() != '[')) {
                    deque.push('x');
                    break;
                }
                deque.pop();
            }
            System.out.println(deque.isEmpty() ? "yes" : "no");
        };
    }
}
