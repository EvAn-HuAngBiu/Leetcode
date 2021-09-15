package base.offer2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q07
 *
 * @author evan
 * @date 2021/9/15
 */
public class Q07 {
    public static List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
        if (len < 3) {
            return new ArrayList<>();
        }

        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int p, q;
        for (int i = 0; i <= len - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            p = i + 1;
            q = len - 1;
            while (p < q) {
                int sum = nums[i] + nums[p] + nums[q];
                if (sum == 0) {
                    result.add(List.of(nums[i], nums[p++], nums[q--]));
                    while (p < q && nums[p] == nums[p - 1]) {
                        ++p;
                    }

                    while (p < q && nums[q] == nums[q + 1]) {
                        --q;
                    }
                } else if (sum > 0) {
                    --q;
                } else {
                    ++p;
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
        System.out.println(threeSum(nums));
    }
}
