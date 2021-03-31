package base;

import java.util.*;

/**
 * Project: LeetCode-Java
 * File: Q90
 *
 * @author evan
 * @date 2021/3/31
 */
class MyList extends ArrayList<Integer> {

}

public class Q90 {
    private List<List<Integer>> result;

    private void dfs(int[] nums, List<Integer> cur, int index) {
        result.add(new ArrayList<>(cur));
        Set<Integer> set = new HashSet<>();
        for (int i = index; i < nums.length; ++i) {
            if (!set.contains(nums[i])) {
                set.add(nums[i]);
                cur.add(nums[i]);
                dfs(nums, cur, i + 1);
                cur.remove(cur.size() - 1);
            }
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        this.result = new ArrayList<>();
        Arrays.sort(nums);
        dfs(nums, new ArrayList<>(), 0);
        return result;
    }

    public static void main(String[] args) {
        Q90 q = new Q90();
        int[] num = {1, 2, 2};
        System.out.println(q.subsetsWithDup(num));
    }
}
