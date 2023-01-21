import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int inf = 100_000 * 2 + 2;

        int[] seconds = new int[inf];
        Arrays.fill(seconds, inf);
        int[] counts = new int[inf];
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(0, n));
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            int s = node.second;
            int p = node.position;
            if (p < 0 || p >= inf) {
                continue;
            }
            if (seconds[p] < s) {
                continue;
            }

            if (seconds[p] == s) {
                counts[p]++;
            }else {
                counts[p] = 1;
                seconds[p] = s;
            }

            queue.add(new Node(s + 1, p * 2));
            queue.add(new Node(s + 1, p + 1));
            queue.add(new Node(s + 1, p - 1));
        }
        bw.write(seconds[k] + "\n" + counts[k]);

        bw.flush();
        bw.close();
        br.close();
    }

    static class Node {
        public int second;
        public int position;

        public Node(int second, int position) {
            this.second = second;
            this.position = position;
        }

    }
}
