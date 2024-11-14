import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static List<String> words = new ArrayList<>();
    static List<Character> alphas = new ArrayList<>();
    
    private static void input() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            
            n = Integer.parseInt(br.readLine());
            boolean[] isExist = new boolean[26];
            for (int i = 0; i < n; i++) {
                String word = br.readLine();
                words.add(word);
                
                for (int j = 0; j < word.length(); j++) {
                    isExist[word.charAt(j) - 'A'] = true;
                }
            }
            
            for (int i = 0; i < 26; i++) {
                if (isExist[i]) {
                    alphas.add((char)('A' + i));
                }
            }
        } catch (Exception e) {
            
        }
    }
    
    static int[] alpha = new int[26];
    private static int getNumber(String word) {
        int result = 0;
        for (int i = 0; i < word.length(); i++) {
            int num = alpha[word.charAt(i) - 'A'];
            result *= 10;
            result += num;
        }
        return result;
    }
    
    private static int getSum() {
        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            int current = getNumber(words.get(i));
            result += current;
        }
        return result;
    }
    
    private static int solve(int current) {
        int result = -1;
        boolean isok = true;
        for (int i = 0; i < alphas.size(); i++) {
            if (alpha[alphas.get(i) - 'A'] == -1) {
                alpha[alphas.get(i) - 'A'] = current;
                isok = false;
                result = Math.max(result, solve(current - 1));
                alpha[alphas.get(i) - 'A'] = -1;
            }
        }
        
        if (isok) {
            return getSum();
        }
        else {
            return result;
        }
    }
    
	public static void main(String[] args) {
	    for (int i = 0; i < 26; i++) {
		    alpha[i] = -1;
		}
	    input();
		System.out.println(solve(9));
	}
}