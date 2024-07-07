import static java.lang.Math.abs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static final BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    private static final char END = 'z' + 1;

    public static void main(String[] args) throws IOException {
        String word1 = bf.readLine();
        String word2 = bf.readLine();
        int[] charCount1 = getCharCountArr(word1);
        int[] charCount2 = getCharCountArr(word2);

        int eraseCount = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            eraseCount += abs(charCount1[c] - charCount2[c]);
        }

        System.out.println(eraseCount);
    }

    private static int[] getCharCountArr(String word) {
        int[] charCount = new int[END];
        for (byte c : word.getBytes())
            charCount[c]++;
        return charCount;
    }
}
