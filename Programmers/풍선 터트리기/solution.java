import java.util.*;

class Solution {
    public int solve(int[] a) {
        if (a.length <= 2) return a.length;
        
        int result = 2;
        int[] checkLeft = new int[a.length];
        int[] checkRight = new int[a.length];
        
        checkLeft[0] = a[0];
        checkRight[a.length - 1] = a[a.length - 1];
        for (int i = 1; i < a.length; i++) {
            checkLeft[i] = Math.min(checkLeft[i - 1], a[i]);
            checkRight[a.length - i - 1] = Math.min(
                checkRight[a.length - i], a[a.length - i - 1]
            );
        }
        
        for (int i = 1; i < a.length - 1; i++) {
            int left = checkLeft[i - 1];
            int right = checkRight[i + 1];
            if (left < a[i] && right < a[i]) continue;
            result++;
        }
        
        return result;
    }
    
    public int solution(int[] a) {
        int answer = solve(a);
        return answer;
    }
}