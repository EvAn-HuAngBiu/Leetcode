package base.offer;

import java.util.HashSet;
import java.util.Set;

public class J13 {
    private int count = 1;
    // 如果要省略这个Set，可以规定只向右和向下即可
    private Set<Integer> set = new HashSet<>();
    private int[][] direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    private void dfs(int m, int n, int k, int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + direct[i][0], ny = y + direct[i][1], hash = nx * 100 + ny;
            int num = nx / 10 + nx % 10 + ny / 10 + ny % 10;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !set.contains(hash) && num <= k) {
                set.add(hash);
                ++count;
                dfs(m, n, k, nx, ny);
            }
        }
    }

    public int movingCount(int m, int n, int k) {
        set.add(0);
        dfs(m, n, k, 0, 0);
        return count;
    }

    public static void main(String[] args) {
        J13 j = new J13();
        System.out.println(j.movingCount(2, 3, 1));
    }
}
