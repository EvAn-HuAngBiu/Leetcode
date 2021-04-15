package base.offer;

/**
 * Project: LeetCode-Java
 * File: J17
 *
 * @author evan
 * @date 2021/4/15
 */
public class J17 {
    public int[] printNumbers(int n) {
        int upper = ((int) Math.pow(10, n));
        int[] array = new int[upper - 1];
        for (int i = 0; i < upper; i++) {
            array[i] = i + 1;
        }
        return array;
    }
}
