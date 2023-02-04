import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        if(n == 1) { // n이어서 소수를 판별할수 없는경우
            System.out.println(0);
            return;
        }
        boolean[] isNotPrime = new boolean[n+1]; // 소수인지 저장하는 array
        List<Integer> primes = new ArrayList<>(); // 연속된 소수들을 담을 list
        for(int i=2; i<=n; i++) {
            if (isNotPrime[i]) continue;
            primes.add(i);
            for (int j=2; i*j<=n; j++) {
                isNotPrime[i*j] = true;
            }
        }
        primes.add(0); // right는 구간합에 포함시키지 않기 위한 더미데이터를 마지막에 삽입
        int left = 0, right = 0; // primes를 탐색하면서 [left, right)의 합이 n이 되는 구간을 찾음
        int prefixSum = 0;
        int answer = 0; // 연속된 소수의 합이 N인 경우의 수
        while(left <= right && right < primes.size()) {
            if (prefixSum < n) { // 구간합이 n보다 작으면 구간을 오른쪽으로 한칸 늘림
                prefixSum += primes.get(right++);
            } else if (prefixSum > n) { // 구간합이 n보다 크면 구간을 왼쪽으로 한칸 줄임
                prefixSum -= primes.get(left++);
            } else { // 구간합이 n과 같으면 구간을 왼쪽으로 한칸 줄임
                prefixSum -= primes.get(left++);
                answer++;
            }
        }
        System.out.println(answer);
    }
}
