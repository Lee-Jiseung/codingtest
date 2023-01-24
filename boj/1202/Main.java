import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    static BufferedWriter bw;
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static int k;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        Jewellery[] jewelleries = new Jewellery[n];
        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            jewelleries[i] = new Jewellery(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(jewelleries, Comparator.comparingInt(jewellery -> jewellery.m));

        int[] cs = new int[k];
        for(int i=0; i<k; i++) {
            cs[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(cs);

        long answer = 0L;
        PriorityQueue<Jewellery> pq = new PriorityQueue<>(Comparator.reverseOrder());
        int index = 0;
        for(int c : cs) {
            while (index < n && jewelleries[index].m <= c) {
                pq.add(jewelleries[index++]);
            }
            if (pq.isEmpty()) continue;

            Jewellery j = pq.poll();
            answer += j.v;
        }

        bw.write(answer + "\n");
        bw.flush();
        bw.close();
        br.close();
    }

    static class Jewellery implements Comparable<Jewellery> {
        int m, v;

        public Jewellery(int m, int v) {
            this.m = m;
            this.v = v;
        }

        @Override
        public int compareTo(Jewellery jewellery) {
            return Integer.compare(this.v, jewellery.v);
        }
    }
}
