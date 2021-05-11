package base;

import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;

/**
 * Project: LeetCode-Java
 * File: Q1734
 *
 * @author evan
 * @date 2021/5/11
 */
public class Q1734 {
    private static boolean[] visited;
    private static LinkedList<Integer> result;

    private static boolean dfs(int[] encoded, int next) {
        if (next == encoded.length + 1) {
            return true;
        }
        for (int i = 1; i <= encoded.length + 1; ++i) {
            if (!visited[i] && (result.getLast() ^ i) == encoded[next - 1]) {
                visited[i] = true;
                result.add(i);
                if (dfs(encoded, next + 1)) {
                    return true;
                }
                result.pop();
                visited[i] = false;
            }
        }
        return false;
    }

    public static int[] decode(int[] encoded) {
        result = new LinkedList<>();
        visited = new boolean[encoded.length + 2];
        for (int i = 1; i <= encoded.length + 1; ++i) {
            result.push(i);
            visited[i] = true;
            if (dfs(encoded, 1)) {
                int[] cur = new int[encoded.length + 1];
                Iterator<Integer> iterator = result.iterator();
                for (int j = 0; j < encoded.length + 1; ++j) {
                    cur[j] = iterator.next();
                }
                return cur;
            }
            visited[i] = false;
            result.pop();
        }
        return null;
    }

    public static int[] decode1(int[] encoded) {
        int len = encoded.length;
        int odd = 0, total = 0;
        for (int i = 0; i < len; ++i) {
            if (i % 2 == 1) {
                odd ^= encoded[i];
            }
            total ^= (i + 1);
        }
        total ^= len + 1;
        int[] result = new int[len + 1];
        result[0] = total ^ odd;
        for (int i = 1; i <= len; ++i) {
            result[i] = result[i - 1] ^ encoded[i - 1];
        }
        return result;
    }

    public static void main(String[] args) {
        int[] encoded = {6, 5, 4, 6};
        System.out.println(Arrays.toString(decode1(encoded)));
    }
}
