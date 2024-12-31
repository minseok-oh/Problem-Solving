import java.util.*;
import java.io.*;

public class Main {
    short[] points;
    int[][][] memo = new int[100001][5][5];
    
    private void input() {
        try {
            var br = new BufferedReader(new InputStreamReader(System.in));
            String[] parts = br.readLine().split(" ");
            
            points = new short[parts.length - 1];
            for (int i = 0; i < parts.length - 1; i++) {
                points[i] = Short.parseShort(parts[i]);
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    private int getMoveFactor(int current, int next) {
        if (current == next) return 1;
        if (current == 0) return 2;
        if (current % 2 != next % 2) return 3;
        return 4;
    }
    
    private int move(int cur, int curLeft, int curRight) {
        if (cur == points.length) {
            return 0;
        }
        if (memo[cur][curLeft][curRight] != 0) {
            return memo[cur][curLeft][curRight];
        }
        if (memo[cur][curRight][curLeft] != 0) {
            return memo[cur][curRight][curLeft];
        }
        
        int next = points[cur];
        int leftMove = move(cur + 1, next, curRight) + getMoveFactor(curLeft, next);
        int rightMove = move(cur + 1, curLeft, next) + getMoveFactor(curRight, next);
        return memo[cur][curLeft][curRight] = Math.min(leftMove, rightMove);
    }
    
	public static void main(String[] args) {
	    var main = new Main();
	    main.input();
	    System.out.println(main.move(0, 0, 0));
	}
}