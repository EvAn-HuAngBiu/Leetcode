package niuke.meituan;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0802
 *
 * @author evan
 * @date 2021/8/25
 */
public class S2021G0802 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();

        // int[] eSum = new int[n + 1], fSum = new int[n + 1];
        // for (int i = 1; i <= n; ++i) {
        //     char c = s.charAt(i - 1);
        //     if (c == 'E') {
        //         eSum[i] = eSum[i - 1] + 1;
        //         fSum[i] = fSum[i - 1];
        //     } else {
        //         eSum[i] = eSum[i - 1];
        //         fSum[i] = fSum[i - 1] + 1;
        //     }
        // }
        //
        // int maxCount = 0;
        // for (int i = 0; i <= n; ++i) {
        //     for (int j = i + 1; j <= n; ++j) {
        //         maxCount = Math.max(maxCount, Math.abs(eSum[j] - eSum[i] - (fSum[j] - fSum[i])));
        //     }
        // }
        // System.out.println(maxCount);

        int pre = 0;
        int maxCount = 0;
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (c == 'E') {
                pre = pre + 1;
                maxCount = Math.max(maxCount, pre);
            } else {
                // 如果一连串F已经是负数了，那么遇到下一个E的时候直接从0开始，即舍弃前面所有的串
                pre = Math.max(pre - 1, 0);
            }
        }
        System.out.println(maxCount);
    }
}
