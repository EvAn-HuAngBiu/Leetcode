package game;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Project: LeetCode-Java
 * File: G5714
 *
 * @author evan
 * @date 2021/3/29
 */
public class G5714 {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> key = new HashMap<>(knowledge.size());
        for (List<String> k : knowledge) {
            key.put(k.get(0), k.get(1));
        }
        StringBuilder sb = new StringBuilder();
        StringBuilder temp = new StringBuilder();
        boolean flag = false;
        for (int i = 0; i < s.length(); ++i) {
            char cur = s.charAt(i);
            if (Character.isLetter(cur)) {
                if (flag) {
                    temp.append(cur);
                } else {
                    sb.append(cur);
                }
            } else if (cur == '(') {
                flag = true;
            } else {
                sb.append(key.getOrDefault(temp.toString(), "?"));
                temp.delete(0, temp.length());
                flag = false;
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        G5714 g = new G5714();
        List<List<String>> l = new ArrayList<>();
        l.add(List.of("a", "b"));
        l.add(List.of("b", "a"));
        System.out.println(g.evaluate("(a)(b)", l));
    }
}
