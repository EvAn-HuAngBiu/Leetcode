package base.offer;

import java.util.LinkedList;

class CQueue {
    private LinkedList<Integer> in;
    private LinkedList<Integer> out;

    public CQueue() {
        in = new LinkedList<>();
        out = new LinkedList<>();
    }
    
    public void appendTail(int value) {
        in.push(value);
    }
    
    public int deleteHead() {
        if (out.isEmpty()) {
            while (!in.isEmpty()) {
                out.push(in.pop());
            }
        }
        return out.isEmpty() ? -1 : out.pop();
    }
}

public class J09 {
    public static void main(String[] args) {
        CQueue queue = new CQueue();
        queue.appendTail(1);
        queue.appendTail(2);
        queue.appendTail(3);
        queue.appendTail(4);
        System.out.println(queue.deleteHead());
    }
}
