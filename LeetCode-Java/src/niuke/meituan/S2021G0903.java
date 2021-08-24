package niuke.meituan;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0903
 *
 * @author evan
 * @date 2021/8/24
 */
public class S2021G0903 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; ++i) {
            int cnt = in.nextInt(), cur;
            boolean allNeg = true;
            int[] lists = new int[cnt];
            int sum = 0;
            for (int j = 0; j < cnt; ++j) {
                cur = in.nextInt();
                sum += cur;
                if (cur > 0) {
                    allNeg = false;
                }
                lists[j] = cur;
            }
            if (allNeg) {
                System.out.println(0);
                continue;
            }

            int maxRate = lists[0];
            int[] rates = new int[cnt];
            rates[0] = lists[0];
            for (int j = 1; j < cnt; ++j) {
                rates[j] = Math.max(rates[j - 1] + lists[j], lists[j]);
                maxRate = Math.max(maxRate, rates[j]);
            }

            /*
            * 循环数组最大连续子序列和问题：
            * 1. 先按正常顺序求不循环的时候最大子序列和
            * 2. 接着解决如果出现循环的时候最大子序列出现的场景，如果出现循环，那么只要排除不循环时最小子序列和，
            *    再用整个数组总和减去最小子序列和就是出现循环时的最大子序列和了。求最小子序列可以转化为求当前数组
            *    全部取负值时的最大子序列即可
            * */
            int negMaxRate = -lists[0], pre = -lists[0];
            for (int j = 1; j < cnt; ++j) {
                pre = Math.max(pre - lists[j], -lists[j]);
                negMaxRate = Math.max(negMaxRate, pre);
            }
            System.out.println(Math.max(maxRate, sum + negMaxRate));
        }
    }
}
