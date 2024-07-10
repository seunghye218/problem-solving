import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {

    private static final BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        Deque<Integer> deque = new ArrayDeque<>();
        int K = Integer.parseInt(bf.readLine());
        for (int i = 0; i < K; ++i) {
            int n = Integer.parseInt(bf.readLine());
            if (n == 0) {
                deque.pop();
            } else {
                deque.push(n);
            }
        }

        int res = 0;
        for (int n : deque)
            res += n;
        System.out.println(res);
    }
}
