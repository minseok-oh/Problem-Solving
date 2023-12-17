import java.util.*;

class Solution {
    private ArrayList<Boolean> visited = new ArrayList<Boolean>();
    private void initList(int size) {
        for (int i = 0; i < size; i++) {
            visited.add(false);
        }
    }
    
    private int visitDungeons(int fatigue, int count, int[][] dungeons) {
        int result = count;
        for (int d = 0; d < dungeons.length; d++) {
            if (visited.get(d)) continue;
            
            if (fatigue >= dungeons[d][0]) {
                visited.set(d, true);
                int value = visitDungeons(fatigue - dungeons[d][1], count + 1, dungeons);
                visited.set(d, false);
                
                result = Math.max(result, value);
            }
        }
        return result;
    }
    
    public int solution(int k, int[][] dungeons) {
        initList(dungeons.length);
        int answer = visitDungeons(k, 0, dungeons);
        return answer;
    }
}