import java.util.*;

class Solution {
    private int MAX = 10000;
    
    public int solution(int[] citations) {
        int[] count = new int[MAX + 1];
        for (int i = 0; i <= MAX; i++) count[i] = 0;
        
        ArrayList<Integer> ci = new ArrayList<>();
        for (int i = 0; i < citations.length; i++) {
            ci.add(citations[i]);
            count[citations[i]]++;
        }
        
        int answer = 0, size = ci.size();
        ci.sort((s1, s2) -> s1.compareTo(s2));
        for (int i = 1; i <= size; i++) {
            count[i] = count[i - 1] + count[i];
            if (count[i] <= i && i <= size - count[i - 1]) answer = i;
        }
        return answer;
    }
}