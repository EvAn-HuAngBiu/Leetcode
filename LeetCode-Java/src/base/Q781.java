package base;

import java.util.HashMap;
import java.util.Map;

/**
 * Project: LeetCode-Java
 * File: Q781
 *
 * @author evan
 * @date 2021/4/4
 */
public class Q781 {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (int i : answers) {
            if (counter.containsKey(i)) {
                counter.put(i, counter.get(i).intValue() + 1);
            } else {
                counter.put(i, 1);
            }
        }
        int result = 0;
        for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
            int k = entry.getKey(), v = entry.getValue();
            if (v % (k + 1) == 0) {
                result += v;
            } else {
                result += (k + 1) * Math.ceil(1.0 * v / (k + 1));
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Q781 q = new Q781();
        int[] answer = {1, 1, 10, 10, 10};
        System.out.println(q.numRabbits(answer));
    }
}
