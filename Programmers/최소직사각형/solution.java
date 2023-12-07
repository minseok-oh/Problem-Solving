import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        ArrayList<Integer> big = new ArrayList<>();
        ArrayList<Integer> small = new ArrayList<>();
        
        for (int[] size: sizes) {
            if (size[0] < size[1]) {
                big.add(size[1]);
                small.add(size[0]);
            }
            else {
                big.add(size[0]);
                small.add(size[1]);
            }
        }
        
        int answer = Collections.max(big) * Collections.max(small);
        return answer;
    }
}