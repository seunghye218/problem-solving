import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static final BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    private static final char END = 'z' + 1;

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());

        for (int i = 0; i < N; ++i) {
            String[] words = bf.readLine().split(" ");
            if (words[0].length() != words[1].length()) {
                System.out.println("Impossible");
                continue;
            }

            int[] charCount = getCharCountArr(words[0]);
            int[] charCount2 = getCharCountArr(words[1]);

            int j = 0;
            for (; j < END; ++j) {
                if (charCount[j] != charCount2[j]) {
                    break;
                }
            }
            if (j == END) {
                System.out.println("Possible");
            } else {
                System.out.println("Impossible");
            }
        }
    }

    private static int[] getCharCountArr(String word) {
        int[] charCount = new int[END];
        for (byte c : word.getBytes())
            charCount[c]++;
        return charCount;
    }
}
