import java.io.*;
import java.util.*;

public class Main {
    
    private int n;
    private long[][][] memo;
    private final int MOD_FACTOR = 1_000_000_000;
    
    private void input() {
        try {
            var br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    private void init() {
        memo = new long[10][101][1024];
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 101; j++) {
                Arrays.fill(memo[i][j], -1);
            }
        }
    }
    
    private long solve(int current, int size, int set) {
        if (size == n) {
            if (set == (1 << 10) - 1) return 1;
            else return 0;
        }
        if (memo[current][size][set] != -1) {
            return memo[current][size][set];
        }
        
        int answer = 0;
        if (current != 0) {
            answer += solve(current - 1, size + 1, set | (1 << (current - 1))) % MOD_FACTOR;
        }
        answer %= MOD_FACTOR;
        
        if (current != 9) {
            answer += solve(current + 1, size + 1, set | (1 << (current + 1))) % MOD_FACTOR;
        }
        answer %= MOD_FACTOR;
        return memo[current][size][set] = answer;
    }
    
    private long solveAll() {
        long answer = 0;
        for (int i = 1; i <= 9; i++) {
            answer += solve(i, 1, 1 << i);
            answer %= MOD_FACTOR;
        }
        return answer % MOD_FACTOR;
    }
    
	public static void main(String[] args) {
	    var main = new Main();
	    main.input();
	    main.init();
	    System.out.println(main.solveAll());
	}
}