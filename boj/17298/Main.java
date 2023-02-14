import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] nums = new int[n];
        for(int i=0; i<n; i++) {
        	nums[i] = Integer.parseInt(st.nextToken());
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int[] nge = new int[n];
        for(int i=n-1; i>=0; i--) {
        	while(!pq.isEmpty()) {
    			if(pq.peek() <= nums[i]) {
    				pq.poll();
    			}else {
    				break;
    			}
    		}
        	if(pq.isEmpty()) {
        		nge[i] = -1;
        	}else {
        		nge[i] = pq.peek();
        	}
    		pq.add(nums[i]);
        }
        for(int i : nge) {
        	bw.write(i + " ");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
