import java.util.*;

class Solution {
    private String first = "12345";
    private String second = "21232425";
    private String third = "3311224455";
    
    private void init(String[] values) {
        for (int i = 0; i < 2000; i++) {
            values[0] = values[0].concat(first);
            values[1] = values[1].concat(second);
            values[2] = values[2].concat(third);
        }
    }
    
    private int[] getScore(int[] answers, String[] values) {
        int[] score = {0, 0, 0};
        for (int i = 0; i < answers.length; i++) {
            for (int j = 0; j < 3; j++) {
                if (answers[i] + '0' == values[j].charAt(i)) {
                    score[j]++;
                }
            }
        }
        return score;
    }
    
    private int getMax(int[] score) {
        int result = -1;
        for (int i = 0; i < score.length; i++)
            if (result < score[i])
                result = score[i];
        return result;
    }
    
    public ArrayList<Integer> solution(int[] answers) {
        String[] values = {"", "", ""};
        init(values);
        int[] score = getScore(answers, values);
        int max = getMax(score);
        
        ArrayList<Integer> answer = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            if (score[i] == max) answer.add(i+1);
        }
        return answer;
    }
}