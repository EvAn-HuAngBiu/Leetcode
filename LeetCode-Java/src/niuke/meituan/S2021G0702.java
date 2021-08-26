package niuke.meituan;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0702
 *
 * @author evan
 * @date 2021/8/26
 */
public class S2021G0702 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] param = br.readLine().trim().split(" ");
        int n = Integer.parseInt(param[0]), m = Integer.parseInt(param[1]), p = Integer.parseInt(param[2]), q = Integer.parseInt(param[3]);
        char[][] graph = new char[n][m];

        int x = 0, y =0;
        for (int i = 0; i < n; ++i) {
            graph[i] = br.readLine().toCharArray();
            for (int j = 0; j < m; ++j) {
                if (graph[i][j] == 'S') {
                    x = i;
                    y = j;
                }
            }
        }

        String path = br.readLine().trim();
        Map<Character, int[]> map = new HashMap<>(4);
        map.put('W', new int[] {-1, 0});
        map.put('S', new int[] {1, 0});
        map.put('D', new int[] {0, 1});
        map.put('A', new int[] {0, -1});

        long point = 0;

        for (int i = 0; i < path.length(); ++i) {
            char cur = path.charAt(i);
            int[] op = map.get(cur);
            int nx = x + op[0], ny = y + op[1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == '#') {
                continue;
            }
            x = nx;
            y = ny;
            char g = graph[x][y];
            if (g == 'O') {
                point += p;
            } else if (g == 'X') {
                point -= q;
            }
            graph[x][y] = '+';
        }

        System.out.println(point);
    }
}
