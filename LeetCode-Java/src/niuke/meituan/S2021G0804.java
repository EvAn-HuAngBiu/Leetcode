package niuke.meituan;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0804
 *
 * @author evan
 * @date 2021/8/25
 */
public class S2021G0804 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] data = br.readLine().split(" ");
        int n = Integer.parseInt(data[0]),
                m = Integer.parseInt(data[1]),
                xs = Integer.parseInt(data[2]),
                ys = Integer.parseInt(data[3]),
                xt = Integer.parseInt(data[4]),
                yt = Integer.parseInt(data[5]);
        int[][] aij = new int[n + 1][m + 1], bij = new int[n + 1][m + 1];
        boolean[][] visited = new boolean[n + 1][m + 1];
        for (int i = 1; i <= n; ++i) {
            data = br.readLine().trim().split(" ");
            for (int j = 1; j <= m; ++j) {
                aij[i][j] = Integer.parseInt(data[j - 1]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            data = br.readLine().split(" ");
            for (int j = 1; j <= m; ++j) {
                bij[i][j] = Integer.parseInt(data[j - 1]);
            }
        }

        final int[] nextOp = {1, -1};
        visited[xs][ys] = true;
        Queue<int[]> queue = new LinkedList<>();
        // 结构：x，y，t
        int[] cur;
        int time;
        queue.add(new int[] {xs, xt, 0});
        while (!queue.isEmpty()) {
            cur = queue.poll();
            if (cur[0] == xt && cur[1] == yt) {
                System.out.println(cur[2]);
                return;
            }
            time = cur[2];
            // 不动
            queue.add(new int[] {cur[0], cur[1], time + 1});
            // 行操作
            int a = aij[cur[0]][cur[1]], b = bij[cur[0]][cur[1]];
            int left = time % (a + b);
            if (left < a) {
                for (int op : nextOp) {
                    int nx = cur[0] + op, ny = cur[1];
                    if (nx <= 0 || nx > n || visited[nx][ny]) {
                        continue;
                    }
                    queue.add(new int[] {nx, ny, time + 1});
                    visited[nx][ny] = true;
                }
            } else {
                for (int op : nextOp) {
                    int nx = cur[0], ny = cur[1] + op;
                    if (ny <= 0 || ny > m || visited[nx][ny]) {
                        continue;
                    }
                    queue.add(new int[] {nx, ny, time + 1});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
