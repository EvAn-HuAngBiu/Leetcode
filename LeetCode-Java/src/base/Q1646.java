package base;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q1646
 *
 * @author evan
 * @date 2021/8/23
 */
public class Q1646 {
    public static int getMaximumGenerated(int n) {
        if (n == 0) {
            return 0;
        }
        int[] array = new int[n + 1];
        array[1] = 1;
        int maxValue = array[1];
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0) {
                array[i] = array[i / 2];
            } else {
                array[i] = array[(i - 1) / 2] + array[(i - 1) / 2 + 1];
            }
            maxValue = Math.max(maxValue, array[i]);
        }
        return maxValue;
    }

    public static void main(String[] args) {
        System.out.println(getMaximumGenerated(1));
    }
}
