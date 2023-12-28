import java.util.*;

class Solution {
    private boolean isOk(String s1, String s2) {
        int result = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) result++;
        }
        return result == 1;
    }
    
    private int getShortestPath(String begin, String target, ArrayList<String> words) {
        Queue<String> q = new LinkedList<>();
        HashMap<String, Integer> visited = new HashMap<>();
        for (String word: words) visited.put(word, -1);
        
        q.add(begin); 
        visited.put(begin, 0);
        
        while (q.size() != 0) {
            String here = q.remove();
            Integer hereVisited = visited.get(here);
            if (here.equals(target)) return hereVisited.intValue();
            
            for (String word: words) {
                if (!isOk(here, word)) continue;
                if (visited.get(word) != -1) continue;
                
                q.add(word);
                visited.put(word, hereVisited + 1);
            }
        }
        return 0;
    }
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        ArrayList<String> wordList = new ArrayList<>(Arrays.asList(words));
        
        if (wordList.contains(target)) {
            answer = getShortestPath(begin, target, wordList);
        }
        return answer;
    }
}