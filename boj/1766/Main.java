import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Pair implements Comparable<Pair> {
        int num, count;

        public Pair(int num, int count) {
            this.num = num;
            this.count = count;
        }

        @Override
        public int compareTo(Pair pair) {
            if (count == pair.count) {
                return num - pair.num;
            }
            return count - pair.count;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] counts = new int[n+1]; // i번째가 선행되어야 하는 문제 수
        List<List<Integer>> priorities = new ArrayList<>(); // i번째 pq엔 i번째 문제보다 먼저 풀어여 할 문제들이 저장되어있다.
        for(int i=0; i<=n; i++) {
            priorities.add(new ArrayList<>());
        }
        for(int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            priorities.get(a).add(b);
            counts[b]++;
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>(); // (번호, 선행되어야할문제수)
        for(int i=1; i<=n; i++) {
            pq.add(new Pair(i, counts[i]));
        }
        boolean[] visited = new boolean[n + 1]; // 문제 방문여부
        StringBuilder answer = new StringBuilder(""); // 정답 문자열
        for(int i=0; i<n; i++) {
            Pair pair;
            while (true) {
                pair = pq.poll();
                if(!visited[pair.num]) break;  // 아직 방문하지 않은 문제 찾기
            }
            visited[pair.num] = true; // 방문 처리
            answer.append(pair.num); // 정답 문자열 만들기
            answer.append(" ");
            for(Integer a : priorities.get(pair.num)) {
                if(!visited[a]) {
                    pq.add(new Pair(a, --counts[a])); // 방문하지않은 문제 중 먼저 풀어야 할 문제가 줄어든 문제 pq에 추가
                }
            }
        }
        System.out.println(answer);
    }
}
