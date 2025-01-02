import java.io.*;
import java.util.*;

public class Main {
    
    private int n;
    private int[] r, c;
    private int[][] memo;
    private static int MAX_ANSWER = 987654321;
    
    private void input() {
        try {
            var br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            
            r = new int[n];
            c = new int[n];
            for (int i = 0; i < n; i++) {
                String[] parts = br.readLine().split(" ");
                r[i] = Integer.parseInt(parts[0]);
                c[i] = Integer.parseInt(parts[1]);
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    private void init() {
        memo = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(memo[i], -1);
        }
    }
    
    private int solve(int left, int right) {
        if (left == right) {
            return 0;
        }
        if (left == right + 1) {
            return r[left] * c[left] * c[right];
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        
        int answer = MAX_ANSWER;
        for (int i = left; i < right; i++) {
            int current = solve(left, i) + solve(i + 1, right) + r[left] * c[i] * c[right];
            answer = Math.min(answer, current);
        }
        return memo[left][right] = answer;
    }
    
	public static void main(String[] args) {
	    var main = new Main();
	    main.input();
	    main.init();
	    System.out.println(main.solve(0, main.n - 1));
	}
}