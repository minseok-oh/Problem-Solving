import java.util.*;

class Solution {
    private ArrayList<Integer> splitArray(int[] array, int left, int right) {
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = left-1; i < right; i++) {
            result.add(array[i]);
        }
        return result;
    }
    
    public ArrayList<Integer> solution(int[] array, int[][] commands) {
        ArrayList<Integer> answer = new ArrayList<>();
        for (int i = 0; i < commands.length; i++) {
            ArrayList<Integer> sp = splitArray(array, commands[i][0], commands[i][1]);
            Collections.sort(sp);
            answer.add(sp.get(commands[i][2] - 1));
        }
        return answer;
    }
}