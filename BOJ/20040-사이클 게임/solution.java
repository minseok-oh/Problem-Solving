import java.io.*;
import java.util.*;

public class Main {
    
    private int n, m;
    private int[][] e;
    private int[] parents;
    
    private boolean union(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        
        if (parentU == parentV) {
            return true;
        }
        
        parents[parentU] = parentV;
        return false;
    }
    
    private int find(int u) {
        if (u == parents[u]) {
            return u;
        }
        return parents[u] = find(parents[u]);
    }
    
    private void input() {
        try {
            var br = new BufferedReader(new InputStreamReader(System.in));
            
            String[] parts = br.readLine().split(" ");
            n = Integer.parseInt(parts[0]);
            m = Integer.parseInt(parts[1]);
            
            this.init();
            for (int i = 1; i <= m; i++) {
                parts = br.readLine().split(" ");
                
                int u = Integer.parseInt(parts[0]);
                int v = Integer.parseInt(parts[1]);
                
                e[i][0] = v;
                e[i][1] = u;
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    private void init() {
        e = new int[m + 1][2];
        parents = new int[n];
        
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }
    
    private int solve() {
        for (int i = 1; i <= m; i++) {
            boolean result = union(e[i][0], e[i][1]);
            if (result) return i;
        }
        return 0;
    }
    
	public static void main(String[] args) {
	    var main = new Main();
	    main.input();
	    System.out.println(main.solve());
	}
}