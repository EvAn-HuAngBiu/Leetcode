package base;

import java.util.HashSet;
import java.util.Set;

/**
 * Project: LeetCode-Java
 * File: Q91
 *
 * @author evan
 * @date 2021/4/21
 */
public class Q91 {
    // private Set<String> set = new HashSet<>();
    private int cnt = 0;

    private void dfs(String cur, int beg, String tmp) {
        int len = cur.length();
        if (beg == len) {
            // set.add(tmp);
            ++cnt;
            return;
        }
        String sub = cur.substring(beg, beg + 1);
        if (Integer.parseInt(sub) != 0) {
            dfs(cur, beg + 1, tmp + sub);
        }
        if (beg + 2 <= len) {
            sub = cur.substring(beg, beg + 2);
            int num = Integer.parseInt(sub);
            if (num >= 10 && num <= 26) {
                dfs(cur, beg + 2, tmp + sub);
            }
        }
    }

    public int numDecodings(String s) {
        dfs(s, 0, "");
        return cnt;
    }

    public int numDecodings2(String s) {
        int len = s.length();
        int[] dp = new int[len + 1];
        dp[0] = 1;
        for (int i = 1; i <= len; ++i) {
            String sub = s.substring(i - 1, i);
            if (Integer.parseInt(sub) != 0) {
                dp[i] += dp[i - 1];
            }
            if (i > 1) {
                sub = s.substring(i - 2, i);
                int num = Integer.parseInt(sub);
                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[len];
    }

    public static void main(String[] args) {
        Q91 q = new Q91();
        System.out.println(q.numDecodings2("06"));
    }
}
