import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        Deque<Integer> dq = new ArrayDeque<>();
        StringBuilder sb = new StringBuilder();
        int sq = 1;

        for (int i = 0, N = Integer.parseInt(br.readLine()); i < N; ++i) {
            int n = Integer.parseInt(br.readLine());

            while (true) {
                if (sq < n) {
                    dq.push(sq++);
                    sb.append("+\n");
                } else if (sq == n) {
                    sb.append("+\n-\n");
                    ++sq;
                    break;
                } else {
                    if (dq.isEmpty() || dq.peek() != n) {
                        sb = new StringBuilder("NO");
                    } else {
                        sb.append("-\n");
                        dq.pop();
                    }
                    break;
                }
            }
            if ("NO".contentEquals(sb)) break;
        }
        System.out.println(sb);
    }
}
