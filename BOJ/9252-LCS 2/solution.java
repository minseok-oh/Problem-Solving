import java.io.*;
import java.util.*;

public class Main {
    private String l1, l2;
    private int[][] memo;
    
    private void input() {
        try (var br = new BufferedReader(new InputStreamReader(System.in))) {
            l1 = br.readLine();
            l2 = br.readLine();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    private void solve() {
        memo = new int[l2.length() + 1][l1.length() + 1];
        
        for (int i = 1; i <= l2.length(); i++) {
            for (int j = 1; j <= l1.length(); j++) {
                memo[i][j] = Math.max(memo[i - 1][j], memo[i][j - 1]);
                
                if (l1.charAt(j - 1) == l2.charAt(i - 1)) {
                    memo[i][j] = Math.max(memo[i][j], memo[i - 1][j - 1] + 1);
                }
            }
        }
        
        System.out.println(memo[l2.length()][l1.length()]);
        System.out.println(getLCS(l2.length(), l1.length()));
    }
    
    private String getLCS(int y, int x) {
        int value = memo[y][x];
        if (value == 0) return "";
        
        while (memo[y - 1][x] == value) {
            y--;
        }
        while (memo[y][x - 1] == value) {
            x--;
        }
        
        return getLCS(y - 1, x - 1) + l2.charAt(y - 1);
    }
    
	public static void main(String[] args) {
		var main = new Main();
		main.input();
		main.solve();
	}
}