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
    static int[] nums;
    static int[] result;
    static int[] max_counts;
    static int[] counts;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        nums = new int[n];
        max_counts = new int[10001];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
            max_counts[nums[i]]++;
        }
        Arrays.sort(nums);
        result = new int[m];
        counts = new int[10001];
        method(0, 0);

        bw.flush();
        bw.close();
        br.close();
    }

    static void method(int count, int index) throws Exception {
        if (count == m) {
            for(int i=0; i<m; i++) {
                bw.write(result[i] +" ");
            }
            bw.write("\n");
            return;
        }

        boolean[] flags = new boolean[10001];
        for(int i=0; i<n; i++) {
            int cur = nums[i];
            if(!flags[cur] && max_counts[cur] > counts[cur]) {
                flags[cur] = true;
                counts[cur]++;
                result[count] = cur;
                method(count+1, index);
                counts[cur]--;
            }
        }
    }
}
