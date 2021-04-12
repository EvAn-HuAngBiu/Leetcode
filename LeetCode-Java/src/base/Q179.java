package base;

import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.Collectors;

/**
 * Project: LeetCode-Java
 * File: Q179
 *
 * @author evan
 * @date 2021/4/12
 */
public class Q179 {
    private String result = "";

    // TLE
    private void dfs(int[] nums, String cur, int cnt) {
        if (cnt == nums.length) {
            result = result.compareTo(cur) > 0 ? result : cur;
            return;
        }
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != -1) {
                int temp = nums[i];
                nums[i] = -1;
                dfs(nums, cur + String.valueOf(temp), cnt + 1);
                nums[i] = temp;
            }
        }
    }

    public String largestNumber(int[] nums) {
        dfs(nums, "", 0);
        return result;
    }

    public String largestNumber2(int[] nums) {
        String result = Arrays.stream(nums).mapToObj(String::valueOf).sorted((a, b) -> (b + a).compareTo(a + b))
                .collect(Collectors.joining());
        int i = 0;
        while (i < result.length() - 1) {
            if (result.charAt(i) != '0') {
                break;
            }
            ++i;
        }
        return result.substring(i);
    }

    public static void main(String[] args) {
        Q179 q = new Q179();
        int[] array = {0, 0};
        System.out.println(q.largestNumber2(array));
    }
}
