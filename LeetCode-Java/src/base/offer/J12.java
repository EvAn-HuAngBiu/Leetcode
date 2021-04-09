package base.offer;

public class J12 {
    private char[][] board;
    private String word;
    private boolean[][] visited;
    private int[][] direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    private boolean dfs(int index, int x, int y) {
        if (index == word.length()) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + direct[i][0], ny = y + direct[i][1];
            if (nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length && !visited[nx][ny] && board[nx][ny] == word.charAt(index)) {
                visited[nx][ny] = true;
                if (dfs(index + 1, nx, ny)) {
                    return true;
                }
                visited[nx][ny] = false;
            }
        }
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int m = board.length, n = board[0].length;
        this.visited = new boolean[m][n];
        this.board = board;
        this.word = word;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (this.board[i][j] == word.charAt(0)) {
                    this.visited[i][j] = true;
                    if (dfs(1, i, j)) {
                        return true;
                    }
                    this.visited[i][j] = false;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        char[][] board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
        J12 j = new J12();
        System.out.println(j.exist(board, "ABCCED"));
    }
}
