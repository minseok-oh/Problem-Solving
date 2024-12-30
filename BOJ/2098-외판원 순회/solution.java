import java.util.*;
import java.io.*;

public class Main {
    private int n;
    private int[][] w;
    private int[][] memo;
    
    private static int MAX_ANSWER = 987654321;
    
    private void input() {
        try {
            var br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            w = new int[n][n];
            
            for (int i = 0; i < n; i++) {
                String[] parts = br.readLine().split(" ");
                for (int j = 0; j < n; j++) {
                    w[i][j] = Integer.parseInt(parts[j]);
                }
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }     
    }
    
    private int solve(int current, int status) {
        if (status == (1 << n) - 1) {
            return w[current][0] == 0 ? MAX_ANSWER : w[current][0];
        }

        if (memo[current][status] != -1) {
            return memo[current][status];
        }

        int answer = MAX_ANSWER;
        for (int next = 0; next < n; next++) {
            if ((status & (1 << next)) == 0 && w[current][next] != 0) {
                answer = Math.min(answer, w[current][next] + solve(next, status | (1 << next)));
            }
        }
        return memo[current][status] = answer;
    }
    
    private void bruteForce() {
        memo = new int[n][66_000];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 66_000; j++) {
                memo[i][j] = -1;
            }
        }
		System.out.println(solve(0, 1));
    }
    
	public static void main(String[] args) {
		var main = new Main();
		main.input();
	    main.bruteForce();
	}
}