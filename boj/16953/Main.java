import java.awt.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw;
    static BufferedReader br;
    static long a;
    static long b;


    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());
        Queue<Long> queue1 = new LinkedList<>();
        Queue<Integer> queue2 = new LinkedList<>();
        queue1.add(a);
        queue2.add(0);
        int answer = -1;
        while (!queue1.isEmpty()) {
            long cur = queue1.poll();
            int count = queue2.poll();
            if (cur == b) {
                answer = count + 1;
                break;
            }
            
            if (cur * 2 <= b) {
                queue1.add(cur * 2);
                queue2.add(count+1);
            }
            if (cur * 10 + 1 <= b) {
                queue1.add(cur * 10 + 1);
                queue2.add(count+1);
            }
        }

        bw.write(answer + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
