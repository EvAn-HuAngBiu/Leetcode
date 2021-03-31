package game;

/**
 * Project: LeetCode-Java
 * File: G1800
 *
 * @author evan
 * @date 2021/3/31
 */
public class G1800 {
    public int maxAscendingSum(int[] nums) {
        int max = 0;
        int sum = 0;
        int last = 0;
        for (int i : nums) {
            if (i > last) {
                sum += i;
                last = i;
            } else {
                if (sum > max) {
                    max = sum;
                }
                last = i;
                sum = i;
            }
        }
        return Math.max(sum, max);
    }

    public static void main(String[] args) {
        G1800 g = new G1800();
        int[] nums = {100,10,1};
        System.out.println(g.maxAscendingSum(nums));
    }
}
