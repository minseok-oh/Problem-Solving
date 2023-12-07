import java.util.*;

class Solution {
    public ArrayList<Integer> solution(int[] prices) {
        ArrayList<Integer> answer = new ArrayList<>();
        Stack<Integer> s = new Stack<>();
        
        s.add(0); answer.add(0);
        for (int i = 1; i < prices.length; i++) {
            answer.add(0);
            while (!s.empty() && prices[s.peek()] > prices[i]) {
                answer.set(s.peek(), i - s.peek());
                s.pop();
            }
            s.add(i);
        }
        
        int len = prices.length - 1;
        while (!s.empty()) {
            answer.set(s.peek(), len - s.peek());
            s.pop();
        }
        return answer;
    }
}