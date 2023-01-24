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
    static StringTokenizer st;
    static int n;
    static int[][] board;


    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int answer = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(0, 1, 0));
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (node.r == n - 1 && node.c == n - 1) {
                answer++;
                continue;
            }

            if (node.r + 1 < n && node.c + 1 < n && board[node.r + 1][node.c] != 1 && board[node.r][node.c + 1] != 1 && board[node.r + 1][node.c + 1] != 1) {
                queue.add(new Node(node.r + 1, node.c + 1, 2));
            }
            if (node.d != 1) {
                if (node.c + 1 < n && board[node.r][node.c + 1] != 1) {
                    queue.add(new Node(node.r, node.c + 1, 0));
                }
            }
            if (node.d != 0) {
                if (node.r + 1 < n && board[node.r + 1][node.c] != 1) {
                    queue.add(new Node(node.r + 1, node.c, 1));
                }
            }
        }

        bw.write(answer + "\n");
        bw.flush();
        bw.close();
        br.close();
    }

    static class Node {
        public int r;
        public int c;
        public int d;

        Node(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d = d;
        }
    }
}
