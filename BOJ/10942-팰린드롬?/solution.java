import java.util.*;
import java.io.*;

class Main {
    private int n, m;
    private int[] numbers;
    private int[][] queries;
    private int[][] memo;
    private StringBuilder sb = new StringBuilder();
    
    private void input() {
        try {
            var br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            
            String line = br.readLine();
            String[] parts = line.split(" ");
            
            numbers = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                numbers[i] = Integer.parseInt(parts[i - 1]);
            }
            
            m = Integer.parseInt(br.readLine());
            queries = new int[m][2];
            for (int i = 0; i < m; i++) {
                line = br.readLine();
                parts = line.split(" ");
                
                queries[i][0] = Integer.parseInt(parts[0]);
                queries[i][1] = Integer.parseInt(parts[1]);
            }
            
            br.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    private void init() {
        memo = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                memo[i][j] = -1;
            }
        }
    }
    
    private int query(int s, int e) {
        if (memo[s][e] != -1) {
            return memo[s][e];
        }
        
        if (s == e) {
            return memo[s][e] = 1;
        }
        
        if (e - s == 1 && numbers[s] == numbers[e]) {
            return memo[s][e] = 1;
        }
        
        if (numbers[s] != numbers[e]) {
            return memo[s][e] = 0;
        }
        
        return memo[s][e] = query(s + 1, e - 1);
    }
    
    private void solve() {
        for (int i = 0; i < m; i++) {
            int result = query(queries[i][0], queries[i][1]);
            sb.append(result).append("\n");
        }
        System.out.println(sb);
    }
    
    public static void main(String[] args) {
        Main main = new Main();
        main.input();
        main.init();
        main.solve();
    }
}