import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.StringJoiner;

public class Main {

    private static final BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String[] NK = bf.readLine().split(" ");
        int N = Integer.parseInt(NK[0]);
        int K = Integer.parseInt(NK[1]);

        List<Integer> arr = new ArrayList<>();
        LinkedList<Integer> circleList = new LinkedList<>();
        for (int i = 1; i <= N; ++i) {
            circleList.add(i);
        }
        ListIterator<Integer> it = circleList.listIterator();
        while (!circleList.isEmpty()) {
            int n = 0;
            for (int i = 0; i < K; ++i) {
                if (it.hasNext()) {
                    n = it.next();
                } else {
                    it = circleList.listIterator();
                    n = it.next();
                }
            }
            arr.add(n);
            if (it.hasPrevious()) {
                it.previous();
                it.remove();
            }
        }
        StringJoiner sj = new StringJoiner(", ");
        for (int n : arr) {
            sj.add(String.valueOf(n));
        }
        System.out.println('<' + sj.toString() + '>');
    }
}
