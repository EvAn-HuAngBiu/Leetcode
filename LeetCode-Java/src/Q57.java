import java.util.Arrays;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.function.IntFunction;

/**
 * Project: LeetCode-Java
 * File: Q57
 *
 * @author evan
 * @date 2021/8/4
 */
public class Q57 {
    static class Pair {
        int beg;
        int end;

        public Pair(int beg, int end) {
            this.beg = beg;
            this.end = end;
        }
    }

    public static boolean isInside(int lastEnd, int curBeg) {
        return curBeg <= lastEnd;
    }

    public static boolean isContain(int lastEnd, int curEnd) {
        return curEnd <= lastEnd;
    }

    public static int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals.length == 0) {
            return new int[][] {{newInterval[0], newInterval[1]}};
        }
        // LinkedList<Pair> list = new LinkedList<>();
        LinkedList<int[]> list = new LinkedList<>();
        // LList list = new LList();
        boolean addFlag = true;
        for (int[] interval : intervals) {
            if (addFlag) {
                if (interval[0] > newInterval[0]) {
                    list.add(newInterval);
                    addFlag = false;
                } else if (interval[0] == newInterval[0]) {
                    if (interval[1] <= newInterval[1]) {
                        continue;
                    } else {
                        addFlag = false;
                    }
                }
            }
            // list.add(new Pair(interval[0], interval[1]));
            list.add(interval);
        }
        if (addFlag) {
            // list.add(new Pair(newInterval[0], newInterval[1]));
            list.add(newInterval);
        }

        // LinkedList<Pair> result = new LinkedList<>();
        LinkedList<int[]> result = new LinkedList<>();
        // ListIterator<Pair> it = list.listIterator();
        ListIterator<int[]> it = list.listIterator();
        while (it.hasNext()) {
            if (result.isEmpty()) {
                result.add(it.next());
                continue;
            }
            // Pair cur = it.next(), pre = result.getLast();
            int[] cur = it.next(), pre = result.getLast();
            // if (isInside(pre.end, cur.beg)) {
            //     if (isContain(pre.end, cur.end)) {
            //         continue;
            //     }
            //     cur.beg = pre.beg;
            //     result.removeLast();
            // }
            if (isInside(pre[1], cur[0])) {
                if (isContain(pre[1], cur[1])) {
                    continue;
                }
                cur[0] = pre[0];
                result.removeLast();
            }
            result.addLast(cur);
        }


        // return result.stream().map(p -> new int[]{p.beg, p.end}).toArray(int[][]::new);
        return result.toArray(new int[0][2]);
    }

    public static void main(String[] args) {
        int[][] cur = {
                {1, 5}
        };
        int[][] result = insert(cur, new int[]{2, 7});
        for (int[] array : result) {
            System.out.printf("%d, %d\n", array[0], array[1]);
        }
    }
}
