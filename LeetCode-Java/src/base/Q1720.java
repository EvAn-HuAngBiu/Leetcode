package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q1720
 *
 * @author evan
 * @date 2021/5/6
 */
public class Q1720 {
    public static int[] decode(int[] encoded, int first) {
        int len = encoded.length;
        int[] result = new int[len + 1];
        result[0] = first;
        for (int i = 1; i <= len; ++i) {
            result[i] = encoded[i - 1] ^ first;
            first = result[i];
        }
        return result;
    }

    public static void main(String[] args) {
        int[] array = {6, 2, 7, 3};
        System.out.println(Arrays.toString(decode(array, 4)));
    }
}
