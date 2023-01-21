import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long b = Long.parseLong(st.nextToken());

        long[][] matrix = new long[n][n];
        for (int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                matrix[i][j] = Long.parseLong(st.nextToken());
            }
        }

        List<long[][]> dp = new ArrayList<>(); // A ^ (2 ^ i)
        dp.add(matrix);
        while((long) Math.pow(2, dp.size()) <= b) {
            dp.add(matmul(n, dp.get(dp.size()-1), dp.get(dp.size()-1)));
        }

        matrix = new long[n][n];
        for(int i=0; i<n; i++) {
            matrix[i][i] = 1L;
        }

        for(int i=dp.size()-1; i>=0; i--) {
            if ((long) Math.pow(2, i) <= b) {
                b -= (long) Math.pow(2, i);
                matrix = matmul(n, matrix, dp.get(i));
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n ; j++) {
                bw.write(matrix[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }

    private static long[][] matmul(int n, long[][] longs1, long[][] longs2) {
        long[][] ret = new long[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    ret[i][j] = (ret[i][j] + longs1[i][k] * longs2[k][j]) % 1000;
                }
            }
        }
        return ret;
    }

}
