package niuke.meituan;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0604
 *
 * @author evan
 * @date 2021/8/27
 */
public class S2021G0604 {
    // public static void main(String[] args) throws IOException {
    //     BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    //     String read;
    //     while ((read = bf.readLine()) != null) {
    //         int n = Integer.parseInt(read);
    //         char[] cur = bf.readLine().trim().toCharArray();
    //         if (n == 1) {
    //             System.out.println(1);
    //             continue;
    //         }
    //         long cnt = 0;
    //         Set<String> set = new HashSet<>();
    //         set.add(new String(cur));
    //         Queue<char[]> queue = new LinkedList<>();
    //         queue.add(cur);
    //         while (!queue.isEmpty()) {
    //             cnt = (cnt + 1) % 998244353;
    //             char[] copy = queue.poll();
    //             for (int i = 0; i < n; ++i) {
    //                 if (i > 0 && copy[i] != 'Z' && copy[i - 1] != 'A') {
    //                     char[] temp = Arrays.copyOf(copy, n);
    //                     temp[i] += 1;
    //                     temp[i - 1] -= 1;
    //                     String t = new String(temp);
    //                     if (!set.contains(t)) {
    //                         queue.add(temp);
    //                         set.add(t);
    //                     }
    //                 }
    //                 if (i < n - 1 && copy[i] != 'Z' && copy[i + 1] != 'A') {
    //                     char[] temp = Arrays.copyOf(copy, n);
    //                     temp[i] += 1;
    //                     temp[i + 1] -= 1;
    //                     String t = new String(temp);
    //                     if (!set.contains(t)) {
    //                         queue.add(temp);
    //                         set.add(t);
    //                     }
    //                 }
    //             }
    //         }
    //         System.out.println(cnt);
    //     }
    // }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String read;

        long[][] dp = new long[2611][111];
        dp[0][0] = 1;

        for (int i = 1; i <= 2610; ++i) {
            for (int j = 1; j <= 110; ++j) {
                for (int k = 1; k <= Math.min(26, i); ++k) {
                    dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 998244353;
                }
            }
        }

        while ((read = bf.readLine()) != null) {
            int n = Integer.parseInt(read);
            char[] cur = bf.readLine().trim().toCharArray();
            if (n == 1) {
                System.out.println(1);
                continue;
            }
            int sum = 0;
            for (char c : cur) {
                sum += c - 'A' + 1;
            }

            System.out.println(dp[sum][n]);
        }
    }
}
