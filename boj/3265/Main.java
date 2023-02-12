import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] b = new int[n]; // b 배열
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }
        int[] a = new int[n];
        boolean[] visited = new boolean[n+1]; // 1부터 N까지의 숫자 중에서 a에 사용되었는지 여부
        for(int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int index = Integer.parseInt(st.nextToken()) - 1;
            int value = Integer.parseInt(st.nextToken());
            a[index] = value;
            visited[value] = true;
        }
        int[] mins = new int[n]; // 인덱스 별 가능한 최소값
        int[] maxs = new int[n]; // 인덱스 별 가능한 최대값
        int prev = n; // 이전 최대값
        for(int i=n-1; i>=0; i--) {
            if(b[i] == 1) {
                maxs[i] = i+1;
                prev = i+1;
            }else {
                maxs[i] = prev;
            }
        }
        prev = 1;
        for(int i=0; i<n; i++) {
            if(b[i] == 1) {
                mins[i] = 1;
                prev = 1;
            }else if(prev == 1) {
                mins[i] = i+2;
                prev = 0;
            }else {
                mins[i] = mins[i-1];
            }
        }
        int answer = 0;
        for(int i=0; i<n; i++) {
            if(a[i] != 0) {
                if(a[i] < mins[i] || a[i] > maxs[i]) {
                    answer = -1;
                    break;
                }
            }else {
                for(int j=maxs[i]; j>= mins[i]; j--) {
                    if(!visited[j]) {
                        a[i] = j;
                        visited[j] = true;
                        break;
                    }
                }
                if(a[i] == 0) {
                    answer = -1;
                    break;
                }
            }
        }
        if(answer == -1) {
            bw.write(answer + "\n");
        }else {
            for(int ai : a) {
                bw.write(ai + " ");
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }

}
