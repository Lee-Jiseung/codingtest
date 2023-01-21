import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] nums = new int[n];
        for (int i=0; i<n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        int[] l2r = new int[n];
        List<Integer> lis = new ArrayList<>();
        for(int i=0; i<n; i++) {
            if(i == 0 || lis.get(lis.size()-1) < nums[i]) {
                l2r[i] = lis.size();
                lis.add(nums[i]);
            }else {
                int start = 0;
                int end = lis.size() - 1;
                while (start < end) {
                    int mid = (start + end) / 2;
                    if (lis.get(mid) < nums[i]) {
                        start = mid + 1;
                    }else {
                        end = mid;
                    }
                }
                lis.set(start, nums[i]);
                l2r[i] = start;
            }
        }

        int[] reversedNums = new int[n];
        for(int i=0; i<n; i++) {
            reversedNums[i] = nums[n-1-i];
        }
        int[] r2l = new int[n];
        lis = new ArrayList<>();
        for(int i=0; i<n; i++) {
            if(i == 0 || lis.get(lis.size()-1) < reversedNums[i]) {
                r2l[i] = lis.size();
                lis.add(reversedNums[i]);
            }else {
                int start = 0;
                int end = lis.size() - 1;
                while (start < end) {
                    int mid = (start + end) / 2;
                    if (lis.get(mid) < reversedNums[i]) {
                        start = mid + 1;
                    }else {
                        end = mid;
                    }
                }
                lis.set(start, reversedNums[i]);
                r2l[i] = start;
            }
        }

        int answer = 0;
        for(int i=0; i<n; i++) {
            answer = Math.max(answer, l2r[i] + r2l[n-1-i] + 1);
        }
        bw.write(String.valueOf(answer));
        bw.flush();
        bw.close();
        br.close();
    }
}
