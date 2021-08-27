package niuke.meituan;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0603
 *
 * @author evan
 * @date 2021/8/27
 */
public class S2021G0603 {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] param = bf.readLine().split(" ");
        int n = Integer.parseInt(param[0]), m = Integer.parseInt(param[1]);
        int t = n;
        TreeMap<Integer, Set<String>> map = new TreeMap<>();
        while (t != 1) {
            map.put(t, new HashSet<>(2));
            t /= 2;
        }

        String[] matrix = new String[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = bf.readLine();
        }

        Set<Integer> keys = map.keySet();
        int curRow = 0;
        for (int row : keys) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < row; ++i) {
                sb.append(matrix[i]).append(" ");
            }
            map.get(row).add(sb.toString());

            sb.delete(0, sb.length());
            for (int i = row - 1; i >= 0; --i) {
                sb.append(matrix[i]).append(" ");
            }
            map.get(row).add(sb.toString());

            curRow = row;
            boolean flag = true;
            for (int i = row; i < n - row; i += row) {
                sb = sb.delete(0, sb.length());
                for (int j = 0; j < row; ++j) {
                    sb.append(matrix[i + j]).append(" ");
                }
                if (!map.get(row).contains(sb.toString())) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }

        for (int i = 0; i < curRow; ++i) {
            System.out.println(matrix[i]);
        }
    }
}
