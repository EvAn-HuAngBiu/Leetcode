package base;

import java.util.LinkedList;
import java.util.Stack;

/**
 * Project: LeetCode-Java
 * File: Q232
 *
 * @author evan
 * @date 2021/3/17
 */
class MyQueue {
    private LinkedList<Integer> list;

    /** Initialize your data structure here. */
    public MyQueue() {
        list = new LinkedList<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        list.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return list.pollLast();
    }

    /** Get the front element. */
    public int peek() {
        return list.peekLast();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return list.isEmpty();
    }
}

class MyQueue1 {
    private LinkedList<Integer> in;
    private LinkedList<Integer> out;

    /** Initialize your data structure here. */
    public MyQueue1() {
        in = new LinkedList<>();
        out = new LinkedList<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (out.isEmpty()) {
            while (!in.isEmpty()) {
                out.push(in.pop());
            }
        }
        return out.pop();
    }

    /** Get the front element. */
    public int peek() {
        if (out.isEmpty()) {
            while (!in.isEmpty()) {
                out.push(in.pop());
            }
        }
        return out.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return in.isEmpty() || out.isEmpty();
    }
}

public class Q232 {
}
