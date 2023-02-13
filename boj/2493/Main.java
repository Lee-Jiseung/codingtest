import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] heights = new int[n];
        for(int i=0; i<n; i++) {
        	heights[i] = Integer.parseInt(st.nextToken());
        }
        LinkedList<Integer> towers = new LinkedList<>();
        for(int i=0; i<n; i++) {
        	if(towers.isEmpty()) {
        		bw.write(0 + " ");
        	}else {
        		while(!towers.isEmpty()) {
        			if(heights[towers.getLast()] <= heights[i]) {
        				towers.removeLast();
        			}else {
        				break;
        			}
        		}
        		if(towers.isEmpty()) {
        			bw.write(0 + " ");
        		}else {
        			bw.write(towers.getLast()+1 + " ");
        		}
        	}
        	towers.add(i);
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
