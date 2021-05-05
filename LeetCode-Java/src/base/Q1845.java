package base;

import java.util.PriorityQueue;

/**
 * Project: LeetCode-Java
 * File: Q5731
 *
 * @author evan
 * @date 2021/5/1
 */
class SeatManager {
    private int nextSeat = 1;
    private int maxSeat;
    private final PriorityQueue<Integer> releaseSeat;


    public SeatManager(int n) {
        this.maxSeat = n;
        this.releaseSeat = new PriorityQueue<>();
    }

    public int reserve() {
        if (this.releaseSeat.isEmpty() || this.releaseSeat.peek() > nextSeat) {
            return nextSeat++;
        } else {
            return this.releaseSeat.poll();
        }
    }

    public void unreserve(int seatNumber) {
        releaseSeat.add(seatNumber);
    }
}

public class Q1845 {
    public static void main(String[] args) {
        SeatManager manager = new SeatManager(5);
        System.out.println(manager.reserve());
        System.out.println(manager.reserve());
        manager.unreserve(2);
        manager.unreserve(1);
        System.out.println(manager.reserve());
        System.out.println(manager.reserve());
        System.out.println(manager.reserve());
        System.out.println(manager.reserve());
        manager.unreserve(5);
    }
}
