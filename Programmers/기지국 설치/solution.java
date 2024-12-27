import java.util.*;

class Solution {
    
    private List<Integer> getBlankAreas(int n, int[] stations, int w) {
        int current = 1;
        List<Integer> blankAreas = new ArrayList<>();
        
        for (int station: stations) {
            int left = Math.max(1, station - w);
            int right = Math.min(station + w, n);
            
            if (current < left) {
                blankAreas.add(left - current);
            }
            current = right + 1;
        }
        
        if (current <= n) {
            blankAreas.add(n - current + 1);
        }
        return blankAreas;
    }
    
    public int solution(int n, int[] stations, int w) {
        List<Integer> blankAreas = getBlankAreas(n, stations, w);
        
        int answer = 0;
        int distance = 2 * w + 1;
        for (int i = 0; i < blankAreas.size(); i++) {
            int value = blankAreas.get(i);
            answer += value / distance;
            if (value % distance != 0) answer += 1;
        }
        return answer;
    }
}
