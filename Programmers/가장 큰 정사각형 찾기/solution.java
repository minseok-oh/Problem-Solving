class Solution
{
    static private void init(int[][] memo, int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if ((i == 0 || j == 0) && board[i][j] == 1) memo[i][j] = 1;
                else memo[i][j] = 0;
            }
        }
    }
    
    static private int solve(final int[][] board) {
        int[][] memo = new int[board.length][board[0].length];
        init(memo, board);
        
        int result = -1;
        for (int i = 0; i < board.length; i++) 
            result = result < memo[i][0]? memo[i][0]: result;
        for (int i = 0; i < board[0].length; i++)
            result = result < memo[0][i]? memo[0][i]: result;
        
        for (int i = 1; i < board.length; i++) {
            for (int j = 1; j < board[i].length; j++) {
                if (memo[i - 1][j - 1] == 0 || board[i][j] != 1) memo[i][j] = board[i][j];
                else memo[i][j] = Math.min(Math.min(memo[i - 1][j - 1], memo[i - 1][j]), memo[i][j - 1]) + 1;
                
                int memoResult = memo[i][j] * memo[i][j];
                result = result < memoResult? memoResult: result;
            }
        }
        
        return result;
    }
    
    public int solution(int [][]board)
    {
        int result = solve(board);
        return result;
    }
}