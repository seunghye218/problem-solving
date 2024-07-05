import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        List<int[]> clazzes = new ArrayList<>();
        for (int i = 0; i < 7; ++i) {
            clazzes.add(new int[2]);
        }

        int N = scanner.nextInt();
        int K = scanner.nextInt();
        for (int i = 0; i < N; ++i) {
            int gender = scanner.nextInt();
            int clazz = scanner.nextInt();
            clazzes.get(clazz)[gender]++;
        }

        int roomSize = 0;
        for (int[] clazz : clazzes) {
            roomSize += getRoomSize(clazz[0], K);
            roomSize += getRoomSize(clazz[1], K);
        }

        System.out.println(roomSize);
    }

    private static int getRoomSize(int genderNum, int K) {
        return genderNum / K + (genderNum % K > 0 ? 1 : 0) ;
    }
}
