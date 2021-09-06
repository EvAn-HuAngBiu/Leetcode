package base;

import java.util.LinkedList;
import java.util.List;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q241
 *
 * @author evan
 * @date 2021/9/6
 */
public class Q241 {
    private static List<Integer> doCompute(char[] exp, int beg, int end) {
        StringBuilder sb = new StringBuilder();
        int i = beg;
        List<Integer> result = new LinkedList<>();
        while(i <= end) {
            if (Character.isDigit(exp[i])) {
                sb.append(exp[i]);
            } else {
                char sign = exp[i];
                List<Integer> left = doCompute(exp, beg, i - 1),
                        right = doCompute(exp, i + 1, end);
                for (int l : left) {
                    for (int r : right) {
                        switch (sign) {
                            case '+': result.add(l + r); break;
                            case '-': result.add(l - r); break;
                            case '*': result.add(l * r); break;
                            default: result.add(l / r); break;
                        }
                    }
                }
            }
            i++;
        }
        return result.isEmpty() ? List.of(Integer.parseInt(sb.toString())) : result;
    }

    public static List<Integer> diffWaysToCompute(String expression) {
        return doCompute(expression.toCharArray(), 0, expression.length() - 1);
    }

    public static void main(String[] args) {
        System.out.println(diffWaysToCompute("2*3-4*5"));
    }
}
