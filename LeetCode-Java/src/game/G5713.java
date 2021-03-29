package game;

import java.util.HashSet;
import java.util.Set;

/**
 * Project: LeetCode-Java
 * File: G5713
 *
 * @author evan
 * @date 2021/3/29
 */
public class G5713 {
    public int numDifferentIntegers(String word) {
        Set<String> s = new HashSet<>();
        StringBuilder temp = new StringBuilder();
        int len = word.length();
        for (int i = 0; i < len; i++) {
            char cur = word.charAt(i);
            if (Character.isDigit(cur)) {
                temp.append(cur);
            } else if (temp.length() > 0) {
                if (temp.length() > 1) {
                    for (int j = 0; j < temp.length(); j++) {
                        if (temp.charAt(j) != '0') {
                            temp.delete(0, j);
                            break;
                        }
                    }
                }
                s.add(temp.toString());
                temp.delete(0, temp.length());
            }
        }
        if (temp.length() > 0) {
            if (temp.length() > 1) {
                for (int j = 0; j < temp.length(); j++) {
                    if (temp.charAt(j) != '0') {
                        temp.delete(0, j);
                        break;
                    }
                }
            }
            s.add(temp.toString());
            temp.delete(0, temp.length());
        }
        return s.size();
    }

    public static void main(String[] args) {
        G5713 g = new G5713();
        System.out.println(g.numDifferentIntegers("a123bc34d8ef34"));
    }
}
