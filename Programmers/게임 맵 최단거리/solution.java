import java.util.*;

class Pair <K, V> {
    private K key;
    private V value;
    
    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }
    public K getKey() {
        return key;
    }
    public V getValue() {
        return value;
    }
}

class Solution {
    private final int[] x_grad = {-1, 0, 0, 1};
    private final int[] y_grad = {0, -1, 1, 0};
    
    private int getShortestLengthOfPath(int[][] maps) {
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.add(new Pair(0, 0));
        
        Integer yMax = maps.length - 1;
        Integer xMax = maps[0].length - 1;
        maps[0][0] = 0;
        
        while (q.size() != 0) {
            Pair<Integer, Integer> here = q.remove();
            Integer xHere = here.getKey();
            Integer yHere = here.getValue();
            
            if (xHere == xMax && yHere == yMax) {
                return maps[yHere][xHere] + 1;
            }
            
            for (int dir = 0; dir < 4; dir++) {
                Integer xNext = xHere + x_grad[dir];
                Integer yNext = yHere + y_grad[dir];
                if (xNext < 0 || xNext > xMax) continue;
                if (yNext < 0 || yNext > yMax) continue;
                
                if (maps[yNext][xNext] == 1) {
                    maps[yNext][xNext] = maps[yHere][xHere] + 1;
                    q.add(new Pair(xNext, yNext));
                }
            }
        }
        return -1;
    }
    
    public int solution(int[][] maps) {
        int answer = getShortestLengthOfPath(maps);
        return answer;
    }
}