package interview.pdd;

import java.io.BufferedInputStream;
import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q02
 *
 * @author evan
 * @date 2021/8/22
 */
public class Q02 {
    private static int count(int p, int q) {
        Queue<int[]> queue = new LinkedList<>();
        Set<Integer> state = new HashSet<>();
        state.add(p);
        queue.add(new int[] {p, 0});
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            if (current[0] == q) {
                return current[1];
            }
            int[] nexts = {current[0] - 2, current[0] - 1, current[0] + 1, current[0] * 2};
            for (int next : nexts) {
                // if ((q > current[0] && next < current[0]) || (q < current[0] && next > current[0])) {
                //     continue;
                // }
                if (state.contains(next)) {
                    continue;
                }
                if (next == q) {
                    return current[1] + 1;
                }
                queue.add(new int[] {next, current[1] + 1});
                state.add(next);
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int t = in.nextInt();
        for (int i = 0; i < t; ++i) {
            int p = in.nextInt(), q = in.nextInt();
            if (p == q) {
                System.out.println(0);
            } else {
                System.out.println(count(p, q));
            }
        }
    }
}
