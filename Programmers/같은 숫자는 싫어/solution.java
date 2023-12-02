import java.util.*;

public class Solution {
    public ArrayList<Integer> solution(int []arr) {
        ArrayList<Integer> answer = new ArrayList<>();
        
        for (int i: arr) {
            if (answer.size() == 0) answer.add(i);
            else {
                if (answer.get(answer.size()-1) != i) answer.add(i);
            }
        }
        return answer;
    }
}