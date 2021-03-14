package base;

import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q225
 *
 * @author evan
 * @date 2021/3/14
 */
public class Q225 {
}

class MyStack {
    private LinkedList<Integer> queue;

    /** Initialize your data structure here. */
    public MyStack() {
        queue = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        queue.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.pop();
    }

    /** Get the top element. */
    public int top() {
        return queue.getFirst();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
    }
}