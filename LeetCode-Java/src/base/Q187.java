package base;

import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q187
 *
 * @author evan
 * @date 2021/9/28
 */
public class Q187 {
    public static List<String> findRepeatedDnaSequences(String s) {
        int len = s.length();
        if (len <= 10) {
            return Collections.emptyList();
        }
        Map<String, Integer> map = new HashMap<>(s.length());
        Set<String> result = new HashSet<>();

        for (int i = 0; i <= len - 10; ++i) {
            String sub = s.substring(i, i + 10);
            int next = map.getOrDefault(sub, 0) + 1;
            map.put(sub, next);
            if (next >= 2) {
                result.add(sub);
            }
        }
        return List.copyOf(result);
    }

    public static void main(String[] args) {
        System.out.println(findRepeatedDnaSequences("AAAAAAAAAAA"));
    }
}
