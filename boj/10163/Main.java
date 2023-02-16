import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	StringTokenizer st;
    	int n = Integer.parseInt(br.readLine());
    	int[][] nums = new int[1001][1001];
    	for(int i=0; i<n; i++) {
    		st = new StringTokenizer(br.readLine());
    		int x = Integer.parseInt(st.nextToken());
    		int y = Integer.parseInt(st.nextToken());
    		int r = Integer.parseInt(st.nextToken());
    		int c = Integer.parseInt(st.nextToken());
    		for(int j=0; j<r; j++) {
    			for(int k=0; k<c; k++) {
    				nums[x+j][y+k] = i+1;
    			}
    		}
    	}
    	int[] counts = new int[n+1];
    	for(int i=0; i<1001; i++) {
    		for(int j=0; j<1001; j++) {
    			counts[nums[i][j]]++;
    		}
    	}
    	for(int i=1; i<=n; i++) {
    		bw.write(counts[i] + "\n");
    	}
    	bw.flush();
        bw.close();
        br.close();
    }
}
