import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
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
    	int[][] nums = new int[n][m];
    	for(int i=0; i<n; i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j=0; j<m; j++) {
    			nums[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    	List<Queue<Integer>> list = new ArrayList<>();
    	for(int k=0; k<Math.min(n, m)/2; k++) {
    		Queue<Integer> q = new LinkedList<>();
    		for(int j=k; j<m-1-k; j++) {
    			q.offer(nums[k][j]);
    		}
    		for(int i=k; i<n-1-k; i++) {
    			q.offer(nums[i][m-1-k]);
    		}
    		for(int j=k; j<m-1-k; j++) {
    			q.offer(nums[n-1-k][m-1-j]);
    		}
    		for(int i=k; i<n-1-k; i++) {
    			q.offer(nums[n-1-i][k]);
    		}
    		list.add(q);
    	}
    	for(int i=0; i<list.size(); i++) {
    		for(int j=0; j<r%list.get(i).size(); j++) {
    			int temp = list.get(i).poll();
    			list.get(i).offer(temp);
    		}
    	}
    	for(int k=0; k<list.size(); k++) {
    		Queue<Integer> q = list.get(k);
    		for(int j=k; j<m-k; j++) {
    			nums[k][j] = q.poll();
    		}
    		for(int i=1+k; i<n-k; i++) {
    			nums[i][m-1-k] = q.poll();
    		}
    		for(int j=m-2-k; j>=k; j--) {
    			nums[n-1-k][j] = q.poll();
    		}
    		for(int i=n-2-k; i>=1+k; i--) {
    			nums[i][k] = q.poll();
    		}
    	}
    	for(int[] row : nums) {
    		for(int i : row) {
    			bw.write(i + " ");
    		}
    		bw.write("\n");
    	}
        bw.flush();
        bw.close();
        br.close();
    }
}
