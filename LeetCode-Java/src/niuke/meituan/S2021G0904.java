package niuke.meituan;

import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0904
 *
 * @author evan
 * @date 2021/8/24
 */
public class S2021G0904 {
    private static Map<Integer, Integer> parents;
    private static void unlink(Integer root, Map<Integer, List<Integer>> graph) {
        List<Integer> sub = graph.get(root);
        if (sub == null || sub.isEmpty()) {
            return;
        }
        for (Integer integer : sub) {
            parents.put(integer, root);
            graph.get(integer).remove(root);
            unlink(integer, graph);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int nodeCount = in.nextInt();
        Map<Integer, List<Integer>> graph = new HashMap<>(nodeCount);
        graph.put(1, new ArrayList<>(2));
        parents = new HashMap<>(nodeCount);
        parents.put(1, null);

        for (int i = 0; i < nodeCount - 1; ++i) {
            int n1 = in.nextInt(), n2 = in.nextInt();
            List<Integer> e1 = graph.getOrDefault(n1, new ArrayList<>(2));
            e1.add(n2);
            graph.put(n1, e1);

            List<Integer> e2 = graph.getOrDefault(n2, new ArrayList<>(2));
            e2.add(n1);
            graph.put(n2, e2);
        }
        // 由于输入不知道哪个结点是父节点，哪个是子结点，但是知道1是根节点，所以修正一下图
        // 并且确定每个结点对应的父节点
        unlink(1, graph);

        // 记录每个结点对应的出现最多的颜色的值
        int[] maxColors = new int[nodeCount + 1];
        // 计数器：结点id -> (当前结点下颜色 -> 颜色出现次数）   并查集思想
        Map<Integer, Map<Integer, Integer>> colorCount = new HashMap<>(nodeCount);

        for (int i = 1; i <= nodeCount; ++i) {
            int color = in.nextInt();
            Integer nextId = i;
            do {
                // 获取当前结点的颜色计数器
                Map<Integer, Integer> currentColorCounter = colorCount.getOrDefault(nextId, new HashMap<>());
                // 获取当前输入结点的颜色在父节点中出现的次数
                int currentColorCount = currentColorCounter.getOrDefault(color, 0) + 1;
                // 获取已经记录的颜色出现次数最多的结点出现的次数
                int previousMaxCount = currentColorCounter.getOrDefault(maxColors[nextId], -1);
                // 如果当前颜色出现次数更多，或者两个颜色出现的一样多但是当前颜色值更小，那么修改最大颜色数组对应的颜色
                if (previousMaxCount < currentColorCount || (previousMaxCount == currentColorCount && maxColors[nextId] > color)) {
                    maxColors[nextId] = color;
                }
                currentColorCounter.put(color, currentColorCount);
                colorCount.put(nextId, currentColorCounter);
                nextId = parents.get(nextId);
            } while (nextId != null);
        }

        int q = in.nextInt();
        for (int i = 0; i < q; ++i) {
            System.out.println(maxColors[in.nextInt()]);
        }
    }
}
