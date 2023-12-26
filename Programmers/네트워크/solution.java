class Solution {
    private boolean[] visited = new boolean[200];
    private void init() {
        for (int i = 0; i < 200; i++) {
            visited[i] = false;
        }
    }
    
    private void dfs(int n, int here, int[][] computers) {
        for (int i = 0; i < n; i++) {
            if (computers[here][i] == 1 && !visited[i]) {
                visited[i] = true;
                dfs(n, i, computers);
            }
        }
    }
    
    private int dfsAll(int n, int[][] computers) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true; 
                result++;
                
                dfs(n, i, computers);
            }
        }
        return result;
    }
    
    public int solution(int n, int[][] computers) {
        int answer = dfsAll(n, computers);
        return answer;
    }
}