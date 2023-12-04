import java.util.*;

class Solution {
    private boolean isBiggest(Queue<Integer> q, int[] priorities) {
        boolean isok = true;
        int here = priorities[q.peek()];
        for (int i = 0; i < q.size(); i++) {
            if (here < priorities[q.peek()]) {
                isok = false;
            } 
            q.add(q.peek());
            q.remove();
        }
        return isok;
    }
    
    public int solution(int[] priorities, int location) {
        int answer = 1;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++) q.add(i);
        
        while (q.size() != 0) {
            if (isBiggest(q, priorities)) {
                if (q.peek() == location) break;
                else q.remove();
                answer++;
            }
            else {
                q.add(q.peek());
                q.remove();
            }
        }
        return answer;
    }
}