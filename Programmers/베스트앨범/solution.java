import java.util.*;

class Solution {
    private ArrayList<String> getScoreBoard(String[] genres, int[] plays) {
        Map<String, Integer> entire = new HashMap<>();
        ArrayList<String> result = new ArrayList<>();
        
        for (int i = 0; i < genres.length; i++) {
            String genre = genres[i];
            if (entire.containsKey(genre)) {
                entire.put(genre, entire.get(genre) + plays[i]);
            }
            else {
                entire.put(genre, plays[i]);
                result.add(genre);
            }
        }
        
        result.sort((s1, s2) -> entire.get(s2).compareTo(entire.get(s1)));
        return result;
    }
    
    public ArrayList<Integer> solution(String[] genres, int[] plays) {
        ArrayList<String> scoreBoard = getScoreBoard(genres, plays);
        Map<String, ArrayList<Integer>> genreBoard = new HashMap<>();
        
        for (int i = 0; i < genres.length; i++) {
            String genre = genres[i];
            if (!genreBoard.containsKey(genre)) genreBoard.put(genre, new ArrayList<>());
            genreBoard.get(genre).add(Integer.valueOf(i));
        }
        
        ArrayList<Integer> answer = new ArrayList<>();
        for (String genre: scoreBoard) {
            ArrayList<Integer> listGenre = genreBoard.get(genre);
            listGenre.sort((s1, s2) -> Integer.compare(plays[s2], plays[s1]));
            
            answer.add(listGenre.get(0));
            if (listGenre.size() >= 2) answer.add(listGenre.get(1));
        } 
        return answer;
    }
}