import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class Main {

    private static final BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        for (int i = 0, end = Integer.parseInt(bf.readLine()); i < end; ++i) {
            String log = bf.readLine();
            List<Character> pw = new LinkedList<>();
            ListIterator<Character> cursor = pw.listIterator();
            for (char c : log.toCharArray()) {
                switch (c) {
                    case '<' :
                        if (cursor.hasPrevious())
                            cursor.previous();
                        break;
                    case '>' :
                        if (cursor.hasNext())
                            cursor.next();
                        break;
                    case '-' :
                        if (cursor.hasPrevious()) {
                            cursor.previous();
                            cursor.remove();
                        }
                        break;
                    default :
                        cursor.add(c);
                }
            }

            StringBuilder sb = new StringBuilder();
            for (char c : pw)
                sb.append(c);
            System.out.println(sb);
        }
    }
}
