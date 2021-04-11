package base;

import java.util.List;
import java.util.ArrayList;

public class Q264 {
    public int nthUglyNumber(int n) {
        List<Integer> result = new ArrayList();
        result.add(1);
        int[] next = {0, 0, 0};
        int[] base = {2, 3, 5};
        int index, min, cur;
        while (result.size() != n) {
            index = 0;
            min = base[index] * result.get(next[index]);
            for (int i = 1; i < 3; ++i) {
                cur = base[i] * result.get(next[i]);
                if (cur < min) {
                    min = cur;
                    index = i;
                }
            }
            result.add(min);
            for (int i = 0; i < 3; ++i) {
                while (base[i] * result.get(next[i]) <= min) {
                    ++next[i];
                }
            }
        }
        return result.get(n - 1);
    }

    public static void main(String[] args) {
        Q264 q = new Q264();
        System.out.println(q.nthUglyNumber(10));
    }
}
