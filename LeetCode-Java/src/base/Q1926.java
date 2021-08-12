package base;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Project: LeetCode-Java
 * File: Q1926
 *
 * @author evan
 * @date 2021/8/9
 */
public class Q1926 {
    public static int[][] rec;
    public static int[][] pos = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    private static boolean isBoard(int[] cur) {
        int m = rec.length, n = rec[0].length;
        return (cur[0] == 0 || cur[0] == m - 1 || cur[1] == 0 || cur[1] == n - 1);
    }

    private static int dfs(char[][] maze, int[] cur, boolean start) {
        if (!start && isBoard(cur)) {
            return 0;
        }
        if (rec[cur[0]][cur[1]] != 0) {
            return rec[cur[0]][cur[1]];
        }
        int totalStep = 0x7fffffff;
        for (int[] p : pos) {
            int x = cur[0] + p[0], y = cur[1] + p[1];
            if (x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] == '.') {
                maze[x][y] = '+';
                rec[x][y] = dfs(maze, new int[]{x, y}, false);
                if (rec[x][y] != -1) {
                    totalStep = Math.min(totalStep, rec[x][y]);
                }
                maze[x][y] = '.';
            }
        }
        return (rec[cur[0]][cur[1]] = (totalStep == 0x7fffffff ? -1 : totalStep + 1));
    }

    // public static int nearestExit(char[][] maze, int[] entrance) {
    //     int m = maze.length, n = maze[0].length;
    //     rec = new int[m][n];
    //     maze[entrance[0]][entrance[1]] = '+';
    //     return dfs(maze, entrance, true);
    // }

    static class Tuple {
        int x, y, step;

        public Tuple(int x, int y, int step) {
            this.x = x;
            this.y = y;
            this.step = step;
        }
    }

    public static int nearestExit(char[][] maze, int[] entrance) {
        int m = maze.length, n = maze[0].length;
        Queue<Tuple> queue = new LinkedList<>();
        queue.add(new Tuple(entrance[0], entrance[1], 0));
        int[][] pos = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        maze[entrance[0]][entrance[1]] = '+';
        while (!queue.isEmpty()) {
            Tuple cur = queue.poll();
            for (int[] p : pos) {
                int x = cur.x + p[0], y = cur.y + p[1];
                if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                        return cur.step + 1;
                    }
                    maze[x][y] = '+';
                    queue.add(new Tuple(x, y, cur.step + 1));
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        char[][] maze =
                       {{'+','+','+','+','+','+','+','+','+','+'},
                        {'+','.','.','.','.','.','.','.','.','.'},
                        {'+','.','+','+','+','.','+','.','+','+'},
                        {'+','.','+','+','+','.','+','.','+','+'},
                        {'+','.','+','+','+','.','+','.','+','+'},
                        {'+','.','+','+','+','.','+','.','+','+'},
                        {'+','.','+','+','+','.','+','.','+','+'},
                        {'+','.','+','+','+','.','+','.','+','+'},
                        {'+','.','+','+','.','.','+','.','+','+'},
                        {'+','.','+','+','+','.','+','.','+','+'},
                        {'+','.','+','+','+','.','+','.','+','+'},
                        {'+','.','+','+','+','.','+','+','+','+'},
                        {'+','.','+','+','+','.','+','+','+','+'},
                        {'+','.','.','.','.','.','+','+','+','+'},
                        {'+','+','+','+','+','+','+','+','+','+'}};
        int[] entrance = {8, 5};
        System.out.println(nearestExit(maze, entrance));
    }
}
