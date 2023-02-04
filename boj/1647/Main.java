import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Pair implements Comparable<Pair>{
        int x, y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair pair) {
            return Integer.compare(this.y, pair.y);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<Pair>[] edges = new ArrayList[n + 1]; // edge 저장
        for (int i=1; i<=n; i++) {
            edges[i] = new ArrayList<>();
        }
        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int[] temp = new int[3];
            for (int j = 0; j < 3; j++) {
                temp[j] = Integer.parseInt(st.nextToken());
            }
            edges[temp[0]].add(new Pair(temp[1], temp[2]));
            edges[temp[1]].add(new Pair(temp[0], temp[2]));
        }
        boolean[] visited = new boolean[n+1]; // 방문 여부(트리에 포함 여부)
        PriorityQueue<Pair> pq = new PriorityQueue<>(); // 트리에 포함된 노드에서 나가는 간선 저장
        visited[1] = true; // 트리 초기 설정 - 1번 노드에서 시작
        pq.addAll(edges[1]); // 트리 초기 설정 - 1번 노드에서 나가는 간선 pq에 추가
        int maxC = 0; // 나중에 없애서 트리를 2개로 나눌 트리에서 가장 큰 가중치 저장
        int totalC = 0; // 트리에서 가중치들의 총합
        for(int i = 1; i<n; i++) { // n-1번 반복
            Pair pair;
            while(true) {
                pair = pq.poll();
                if(!visited[pair.x]) break; // 방문하지 않았으면서 가중치가 가장 적은 노드 선택
            }
            visited[pair.x] = true; // 방문 처리
            maxC = Math.max(maxC, pair.y);
            totalC += pair.y;
            for(Pair next : edges[pair.x]) { // 현재 노드에서 갈 수 있는 방문하지 않은 노드와의 간선 추가
                if(!visited[next.x]) pq.add(next);
            }
        }
        System.out.println(totalC - maxC);
    }
}
