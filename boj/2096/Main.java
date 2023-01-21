import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        int[] dpMin = new int[3];
        int[] dpMax = new int[3];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 3; i++) {
            dpMin[i] = Integer.parseInt(st.nextToken());
            dpMax[i] = dpMin[i];
        }

        int[] board = new int[3];
        for (int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                board[j] = Integer.parseInt(st.nextToken());
            }
            int[] tempMin = new int[3];
            int[] tempMax = new int[3];
            tempMin[0] = Math.min(dpMin[0], dpMin[1]) + board[0];
            tempMin[1] = Math.min(dpMin[2], Math.min(dpMin[0], dpMin[1])) + board[1];
            tempMin[2] = Math.min(dpMin[1], dpMin[2]) + board[2];
            tempMax[0] = Math.max(dpMax[0], dpMax[1]) + board[0];
            tempMax[1] = Math.max(dpMax[2], Math.max(dpMax[0], dpMax[1])) + board[1];
            tempMax[2] = Math.max(dpMax[1], dpMax[2]) + board[2];
            dpMin = tempMin;
            dpMax = tempMax;
        }

        bw.write(String.valueOf(Arrays.stream(dpMax).max().getAsInt()));
        bw.write(" ");
        bw.write(String.valueOf(Arrays.stream(dpMin).min().getAsInt()));
        bw.flush();
    }
}
