package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q1723
 *
 * @author evan
 * @date 2021/5/8
 */
public class Q1723 {
    private static int[] payloads;

    private static boolean dfs(int[] jobs, int idx, int times) {
        int len = jobs.length, k = payloads.length;
        if (idx == len) {
            return true;
        }
        for (int i = 0; i < k; ++i) {
            if (payloads[i] + jobs[idx] <= times) {
                payloads[i] += jobs[idx];
                if (dfs(jobs, idx + 1, times)) {
                    return true;
                }
                payloads[i] -= jobs[idx];
            }
            if (payloads[i] == 0 || payloads[i] + jobs[idx] == times) {
                break;
            }
        }
        return false;
    }

    private static boolean judge(int[] jobs, int k, int times) {
        payloads = new int[k];
        return dfs(jobs, 0, times);
    }

    public static int minimumTimeRequired(int[] jobs, int k) {
        Arrays.sort(jobs);
        int beg = jobs[jobs.length - 1], end = Arrays.stream(jobs).sum(), mid;
        while (beg < end) {
            mid = (beg + end) >> 1;
            if (judge(jobs, k, mid)) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }
        return beg;
    }

    public static void main(String[] args) {
        int[] jobs = {6518448,8819833,7991995,7454298,2087579,380625,4031400,2905811,4901241,8480231,7750692,3544254};
        System.out.println(minimumTimeRequired(jobs, 4));
    }
}
