package interview.pdd;

import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q01
 *
 * @author evan
 * @date 2021/8/22
 */
public class Q01 {
    private static Map<Integer, Set<Integer>> map = new HashMap<>();
    private static int maxPrice = 0;

    public static void dfs(int day) {

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t > 0) {
            int n = in.nextInt();
            for (int i = 0; i < n; ++i) {
                int si = in.nextInt(), ti = in.nextInt();
                if (map.containsKey(ti)) {
                    map.get(ti).add(si);
                } else {
                    Set<Integer> set = new TreeSet<>();
                    set.add(si);
                    map.put(ti, set);
                }
            }


            --t;
        }
    }
}
