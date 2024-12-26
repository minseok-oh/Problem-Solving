import java.io.*;
import java.util.*;

class Main {
    private int[][] board = new int[9][9];
    private List<List<Integer>> blank = new ArrayList<>();
    private boolean isok = false;
    private static int MAX_LINE = 9;
    
    private void input() {
        try {
            var bf = new BufferedReader(new InputStreamReader(System.in));
            
            for (int i = 0; i < MAX_LINE; i++) {
                String line = bf.readLine();
                for (int j = 0; j < MAX_LINE; j++) {
                    board[i][j] = Character.getNumericValue(line.charAt(j));
                    if (board[i][j] == 0) {
                        blank.add(List.of(i, j));
                    }
                }
            }
        } catch (Exception e) {
            
        } 
    }
    
    private boolean checkNumber(int y, int x, int num) {
        for (int i = 0; i < MAX_LINE; i++) {
            if (board[y][i] == num || board[i][x] == num) {
                return false;
            }
        }
        
        int baseY = y / 3;
        int baseX = x / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[baseY * 3 + i][baseX * 3 + j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private void solve(int order) {
        if (isok) {
            return;
        }
        if (order == blank.size()) {
            print();
            isok = true;
            return;
        }
        
        int y = blank.get(order).get(0);
        int x = blank.get(order).get(1);
        
        for (int i = 1; i <= 9; i++) {
            if (checkNumber(y, x, i)) {
                board[y][x] = i;
                solve(order + 1);
                board[y][x] = 0;
            }
        }
    }
    
    private void print() {
        for (int i = 0; i < MAX_LINE; i++) {
            for (int j = 0; j < MAX_LINE; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        Main main = new Main();
        main.input();
        main.solve(0);
    }
}