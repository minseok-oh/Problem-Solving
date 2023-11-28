import java.util.Set;
import java.util.HashSet;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        
        Set<Integer> s = new HashSet();
        for (int num: nums) {
            s.add(Integer.valueOf(num));
            answer++;
        }
        
        answer /= 2;
        if (s.size() < answer) answer = s.size();
        return answer;
    }
}