import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    static BufferedWriter bw;
    static BufferedReader br;
    static StringTokenizer st;
    static int v;
    static int e;
    static int[][] board;


    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        st = new StringTokenizer(br.readLine());
        v = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());
        ArrayList<Edge> edges = new ArrayList<>();
        for(int i=0; i<e; i++) {
            st = new StringTokenizer(br.readLine());
            edges.add(new Edge(Integer.parseInt(st.nextToken())-1, Integer.parseInt(st.nextToken())-1, Integer.parseInt(st.nextToken())));
        }
        edges.sort(new EdgeComparator());

        int answer = 0;
        int count = 0;
        int index = 0;
        int[] union = new int[v];
        for(int i=0; i<v; i++) {
            union[i] = i;
        }
        while(count < v-1) {
            Edge edge = edges.get(index++);
            if (union[edge.a] == union[edge.b]) {
                continue;
            }

            int old_union = union[edge.b];
            for(int i=0; i<v; i++) {
                if (union[i] == old_union) {
                    union[i] = union[edge.a];
                }
            }
            count++;
            answer += edge.c;
        }

        bw.write(answer + "\n");
        bw.flush();
        bw.close();
        br.close();
    }

    static class Edge {
        public int a;
        public int b;
        public int c;

        Edge(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static class EdgeComparator implements Comparator<Edge> {
        @Override
        public int compare(Edge edge1, Edge edge2) {
            if(edge1.c > edge2.c) {
                return 1;
            }
            if(edge1.c < edge2.c) {
                return -1;
            }
            return 0;
        }
    }
}
