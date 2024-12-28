class Solution {
    private int getOptimalResult(int[] sticker, int start) {
        int answer = 0;
        int flag = start == 0? 1: 0;
        
        int[] memo = new int[sticker.length];
        memo[start] = sticker[start]; memo[start + 1] = sticker[start + 1];
        answer = Math.max(memo[start], memo[start + 1]);
        for (int i = start + 2; i < sticker.length - flag; i++) {
            memo[i] = sticker[i];
            
            if (i - 2 >= 0) {
                int j = i - 2;
                memo[i] = Math.max(memo[i], memo[j] + sticker[i]);
                answer = Math.max(answer, memo[i]);
            }
            
            if (i - 3 >= 0) {
                int j = i - 3;
                memo[i] = Math.max(memo[i], memo[j] + sticker[i]);
                answer = Math.max(answer, memo[i]);
            }
        }
        
        return answer;
    }
    
    public int solution(int sticker[]) {
        int answer = 0;
        
        if (sticker.length == 1) {
            answer = sticker[0];
        }
        else if (sticker.length == 2) {
            answer = Math.max(sticker[0], sticker[1]);
        }
        else {
            answer = Math.max(answer, getOptimalResult(sticker, 0));
            answer = Math.max(answer, getOptimalResult(sticker, 1));
        }

        return answer;
    }
}
