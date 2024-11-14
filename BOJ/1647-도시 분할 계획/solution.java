import java.util.*;
import java.io.*;

class Path implements Comparable {
    private int u, v, dist;

    public Path(int u, int v, int dist) {
        this.u = u;
        this.v = v;
        this.dist = dist;
    }
    
    @Override
    public int compareTo(Object o) {
        return this.dist - ((Path) o).getDist();    
    }
    
    public int getU() {
        return u;
    }
    
    public int getV() {
        return v;
    }
    
    public int getDist() {
        return dist;
    }
}

class UnionFind {
    private int[] parent = new int[100001];
    
    public UnionFind() {
        for (int i = 0; i < 100001; i++) {
            this.parent[i] = i;
        }
    }
    
    public void union(int u, int v) {
        int parentU = this.find(u);
        int parentV = this.find(v);
        this.parent[parentU] = parentV;
    }
    
    public int find(int u) {
        if (this.parent[u] == u) {
            return u;
        }
        return this.parent[u] = this.find(this.parent[u]);
    }
}

class Main {
    static int n, m;
    static PriorityQueue<Path> paths = new PriorityQueue<>();
    static UnionFind uf = new UnionFind();
    
    private static void input() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            
            String line = br.readLine();
            String[] parts = line.split(" ");
            n = Integer.parseInt(parts[0]);
            m = Integer.parseInt(parts[1]);
            
            for (int i = 0; i < m; i++) {
                line = br.readLine();
                parts = line.split(" ");
                
                int u = Integer.parseInt(parts[0]);
                int v = Integer.parseInt(parts[1]);
                int dist = Integer.parseInt(parts[2]);
                paths.add(new Path(u, v, dist));
            }
        } catch (Exception e) {
            
        }
    }
    
    private static int solve() {
        int result = 0, maxPath = -1;
        while (!paths.isEmpty()) {
            Path path = paths.poll();
            
            int parentU = uf.find(path.getU());
            int parentV = uf.find(path.getV());
            
            if (parentU != parentV) {
                result += path.getDist();
                maxPath = path.getDist();
                uf.union(parentU, parentV);
            }
        }
        return result - maxPath;
    }
    
    public static void main(String[] args) {
        input();
        System.out.println(solve());
    }
}
