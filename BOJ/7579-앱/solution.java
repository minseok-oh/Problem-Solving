import java.util.*;
import java.io.*;

public class Main {
    private int n, m, sum = 0;
    private int[] A;
    private int[] B;
    private int[][] memo;
    
    private void input() {
        try {
            var br = new BufferedReader(new InputStreamReader(System.in));
            
            String line = br.readLine();
            String[] parts = line.split(" ");
            
            n = Integer.parseInt(parts[0]);
            m = Integer.parseInt(parts[1]);
            
            A = new int[n + 1];
            line = br.readLine();
            parts = line.split(" ");
                
            for (int i = 1; i <= n; i++) {
                A[i] = Integer.parseInt(parts[i - 1]);
            }
            
            B = new int[n + 1];
            line = br.readLine();
            parts = line.split(" ");
            
            for (int i = 1; i <= n; i++) {
                B[i] = Integer.parseInt(parts[i - 1]);
                sum += B[i];
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    public int solve() {
        memo = new int[n + 1][100001];
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (B[i] > j) {
                    memo[i][j] = memo[i - 1][j];
                }
                else {
                    memo[i][j] = Math.max(memo[i - 1][j - B[i]] + A[i], memo[i - 1][j]);
                }
            }
        }
        
        for (int i = 0; i <= sum; i++) {
            if (memo[n][i] >= m) {
                return i;
            }
        }
        return -1;
    }
    
	public static void main(String[] args) {
		var main = new Main();
		main.input();
		System.out.println(main.solve());
	}
}