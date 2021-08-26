package niuke.meituan;

import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0704
 *
 * @author evan
 * @date 2021/8/26
 */
public class S2021G0704 {
    static class Node {
        int max = 0;
        int min = Integer.MAX_VALUE;
        int count = 0;
        int pre;
        int id;

        public Node(int id, int pre) {
            this.id = id;
            this.pre = pre;
        }
    }

    private static Node[] nodes;
    private static int[] values;

    private static void unlink(int root, Map<Integer, List<Integer>> graph) {
        List<Integer> subNodes = graph.get(root);
        if (subNodes == null || subNodes.isEmpty()) {
            return;
        }
        for (int node : subNodes) {
            graph.get(node).remove(new Integer(root));
            nodes[node] = new Node(node, root);
            // 向上更新
            int pre = node;
            while (pre != -1) {
                Node cur = nodes[pre];
                cur.max = Math.max(cur.max, values[node]);
                cur.min = Math.min(cur.min, values[node]);
                cur.count += 1;
                pre = cur.pre;
            }
            unlink(node, graph);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), k = in.nextInt();
        Map<Integer, List<Integer>> graph = new HashMap<>(n);
        values = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            values[i] = in.nextInt();
        }
        int e1, e2;
        for (int i = 0; i < n - 1; ++i) {
            e1 = in.nextInt();
            e2 = in.nextInt();

            List<Integer> n1 = graph.getOrDefault(e1, new ArrayList<>(2));
            List<Integer> n2 = graph.getOrDefault(e2, new ArrayList<>(2));
            n1.add(e2);
            n2.add(e1);

            graph.put(e1, n1);
            graph.put(e2, n2);
        }

        int root = in.nextInt();
        nodes = new Node[n + 1];
        nodes[root] = new Node(root, -1);
        unlink(root, graph);

        int maxDiff = 0, idx = Integer.MAX_VALUE;
        for (int i = 1; i <= n; ++i) {
            Node cur = nodes[i];
            if (cur.count <= k) {
                int diff = cur.max - cur.min;
                if (diff > maxDiff || (diff == maxDiff && cur.id < idx)) {
                    maxDiff = diff;
                    idx = cur.id;
                }
            }
        }
        System.out.println(idx);
    }
}
