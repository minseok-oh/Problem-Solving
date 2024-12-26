import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        Arrays.sort(routes, (a, b) -> {
            return a[1] - b[1];
        });
        
        int answer = 1; 
        int end = routes[0][1];
        for (int i = 1; i < routes.length; i++) {
            if (routes[i][0] > end) {
                end = routes[i][1];
                answer++;
            }
        }
        return answer;
    }
}