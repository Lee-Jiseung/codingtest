import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int m;
    static BufferedWriter bw;
    static int[] result;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[] nums = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(nums);

        result = new int[m];
        method(nums, 0, 0);

        bw.flush();
        bw.close();
        br.close();
    }

    static void method(int[] nums, int count, int index) throws Exception {
        if (count == m) {
            for(int i=0; i<m; i++) {
                bw.write(result[i] + " ");
            }
            bw.write("\n");
            return;
        }

        for(int i=index; i<n; i++) {
            result[count] = nums[i];
            method(nums, count+1, i);
        }
    }
}
