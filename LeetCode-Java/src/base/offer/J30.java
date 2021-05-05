package base.offer;

import java.util.LinkedList;

/**
 * Project: LeetCode-Java
 * File: J30
 *
 * @author evan
 * @date 2021/4/27
 */

class MinStack {
    private LinkedList<Integer> stack;
    private LinkedList<Integer> min;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new LinkedList<>();
        min = new LinkedList<>();
        min.push(Integer.MAX_VALUE);
    }

    public void push(int x) {
        if (x <= min.peek()) {
            min.push(x);
        }
        stack.push(x);
    }

    public void pop() {
        if (stack.peek().equals(min.peek())) {
            min.pop();
        }
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int min() {
        return stack.peek() < min.peek() ? stack.peek() : min.peek();
    }
}

public class J30 {
    
}
