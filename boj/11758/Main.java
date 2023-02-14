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
        long[][] coords = new long[3][2];
        for(int i=0; i<3; i++) {
        	st = new StringTokenizer(br.readLine());
        	coords[i][0] = Long.parseLong(st.nextToken());
        	coords[i][1] = Long.parseLong(st.nextToken());
        }
        long ccw = (coords[1][0]-coords[0][0])*(coords[2][1]-coords[0][1]) - (coords[2][0]-coords[0][0])*(coords[1][1]-coords[0][1]);
        if(ccw > 0l) {
        	bw.write(1 + "\n");
        }else if(ccw < 0l) {
        	bw.write(-1 + "\n");
        }else {
        	bw.write(0 + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
