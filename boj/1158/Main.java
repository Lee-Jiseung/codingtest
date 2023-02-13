import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        LinkedList<Integer> nums = new LinkedList<>();
        for(int i=1; i<=n; i++) {
        	nums.add(i);
        }
        bw.write("<");
        for(int i=0; i<n; i++) {
        	for(int j=1; j<k; j++) {
        		nums.add(nums.get(0));
        		nums.remove(0);
        	}
        	bw.write(nums.remove(0) + "");
        	if(i != n-1) {
        		bw.write(", ");
        	}
        }
        bw.write(">\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
