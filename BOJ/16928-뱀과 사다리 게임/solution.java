import java.util.*;
import java.io.*;

public class Main {
    static int n, m;
    static Map<Integer, Integer> passage = new HashMap<>();
    
    private static void input() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            
            String line = br.readLine();
            String[] parts = line.split(" ");
            n = Integer.parseInt(parts[0]);
            m = Integer.parseInt(parts[1]);
            
            for (int i = 0; i < n + m; i++) {
                line = br.readLine();
                parts = line.split(" ");
                
                int start = Integer.parseInt(parts[0]);
                int end = Integer.parseInt(parts[1]);
                passage.put(start, end);
            }
        } catch (Exception e) {
            
        }
    }
    
    private static int solve() {
        final int MAX = 987654321;
        PriorityQueue<List<Integer>> q = new PriorityQueue<>(
            (list1, list2) -> list1.get(0) - list2.get(0));
        int[] visited = new int[101];
        
        for (int i = 0; i < 101; i++) {
            visited[i] = MAX;
        }
        
        visited[1] = 0;
        q.add(new ArrayList<>(Arrays.asList(visited[1], 1)));
        
        while (!q.isEmpty()) {
            List<Integer> current = q.poll();
            if (current.get(1) == 100) {
                return current.get(0);
            }
            
            if (passage.containsKey(current.get(1))) {
                int next = passage.get(current.get(1));
                visited[next] = current.get(0);
                q.add(new ArrayList<>(Arrays.asList(visited[next], next)));
                continue;
            }
            
            for (int i = 1; i <= 6; i++) {
                int next = current.get(1) + i;
                if (next <= 100 && current.get(0) + 1 < visited[next]) {
                    visited[next] = current.get(0) + 1;
                    q.add(new ArrayList<>(Arrays.asList(visited[next], next)));
                }
            }
        }
        return -1;
    }
    
	public static void main(String[] args) {
	    input();
	    System.out.println(solve());
	}
}