package base;

/**
 * Project: LeetCode-Java
 * File: Q387
 *
 * @author evan
 * @date 2021/5/20
 */
public class Q387 {
    public static int firstUniqChar(String s) {
        int[] count = new int[26];
        int[] pos = new int[26];
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            int cur = s.charAt(i) - 'a';
            ++count[cur];
            if (pos[cur] == 0) {
                pos[cur] = i + 1;
            }
        }

        int first = Integer.MAX_VALUE;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 1 && pos[i] < first) {
                first = pos[i];
            }
        }
        return first == Integer.MAX_VALUE ? -1 : first - 1;
    }

    public static void main(String[] args) {
        System.out.println(firstUniqChar("loveleetcode"));
    }
}
