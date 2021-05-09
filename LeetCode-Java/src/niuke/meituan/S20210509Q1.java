package niuke.meituan;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Scanner;

/**
 * Project: LeetCode-Java
 * File: S20210509Q1
 *
 * @author evan
 * @date 2021/5/9
 */
public class S20210509Q1 {
    static class Tuple {
        int x;
        int y;

        public Tuple(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Tuple tuple = (Tuple) o;
            return x == tuple.x && y == tuple.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    private static int minCost = Integer.MAX_VALUE;
    private static Map<Tuple, Map<Tuple, Integer>> graph = new HashMap<>();
    private static Map<Tuple, Boolean> visited = new HashMap<>();

    private static void dfs(Tuple target, Tuple cur, int cost) {
        if (target.equals(cur)) {
            minCost = Math.min(minCost, cost);
            return;
        }
        if (graph.get(cur) == null || graph.get(cur).isEmpty()) {
            return;
        }
        for (Tuple next : graph.get(cur).keySet()) {
            if (!visited.getOrDefault(next, false)) {
                visited.put(next, true);
                dfs(target, next, cost + graph.get(cur).get(next));
                visited.put(next, false);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        for (int i = 0; i < k; ++i) {
            Tuple beg = new Tuple(in.nextInt(), in.nextInt());
            Tuple next = new Tuple(in.nextInt(), in.nextInt());
            int cost = in.nextInt();
            if (graph.containsKey(beg)) {
                graph.get(beg).put(next, cost);
            } else {
                Map<Tuple, Integer> cur = new HashMap<>();
                cur.put(next, cost);
                graph.put(beg, cur);
            }
        }

        Tuple target = new Tuple(n, m);
        Tuple beg = new Tuple(1, 1);
        visited.put(beg, true);
        if (!graph.containsKey(beg)) {
            System.out.println(-1);
            return;
        }
        dfs(target, beg, 0);
        if (minCost == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(minCost);
        }
    }
}
