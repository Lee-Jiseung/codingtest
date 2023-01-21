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
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int[] itemCounts = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            itemCounts[i] = Integer.parseInt(st.nextToken());
        }
        int[][] distances = new int[n][n];
        int inf = 100*15*10;
        for(int i=0; i<n; i++) {
            Arrays.fill(distances[i], inf);
            distances[i][i] = 0;
        }
        for (int i=0; i<r; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken())-1;
            int b = Integer.parseInt(st.nextToken())-1;
            int l = Integer.parseInt(st.nextToken());
            distances[a][b] = l;
            distances[b][a] = l;
        }

        for(int k=0; k<n; k++) {
            for(int start = 0; start<n; start++) {
                for(int end = 0; end<n; end++) {
                    distances[start][end] = Math.min(distances[start][end], distances[start][k] + distances[k][end]);
                }
            }
        }

        int answer = 0;
        for(int i=0; i<n; i++) {
            int temp = 0;
            for(int j=0; j<n; j++) {
                if (distances[i][j] <= m) {
                    temp += itemCounts[j];
                }
            }
            answer = Math.max(answer, temp);
        }

        bw.write(answer + "\n");
        bw.flush();
        bw.close();
        br.close();
    }

}
