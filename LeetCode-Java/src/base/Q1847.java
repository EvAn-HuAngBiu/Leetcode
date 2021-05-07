package base;

import java.util.*;

/**
 * Project: LeetCode-Java
 * File: Q5733
 *
 * @author evan
 * @date 2021/5/1
 */
public class Q1847 {
    class Room {
        private int id;
        private int size;

        public Room(int id, int size) {
            this.id = id;
            this.size = size;
        }
    }

    private int binarySearch(List<Room> rooms, Room key, Comparator<Room> cmp) {
        int start = 0, end = rooms.size() - 1, mid, result;
        while (start <= end) {
            mid = (start + end) >> 1;
            result = cmp.compare(rooms.get(mid), key);
            if (result < 0) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }

    public int[] closestRoom(int[][] rooms, int[][] queries) {
        int len = rooms.length;
        List<Room> r = new ArrayList<>(len);
        for (int[] room : rooms) {
            r.add(new Room(room[0], room[1]));
        }

        r.sort((a, b) -> {
            if (a.size == b.size) {
                return a.id - b.id;
            }
            return a.size - b.size;
        });

        int[] result = new int[queries.length];
        int idx = 0;
        for (int[] query : queries) {
            Room cur = new Room(query[0], query[1]);
            int querySize = binarySearch(r, cur, Comparator.comparingInt(o -> o.size));
            if (querySize < 0 || querySize >= len) {
                result[idx++] = -1;
            } else {
                int minAbs = Integer.MAX_VALUE, pos = querySize;
                for (int i = querySize; i < len; ++i) {
                    int abs = Math.abs(r.get(i).id - query[0]);
                    if (abs < minAbs || (abs == minAbs && r.get(i).id < r.get(pos).id)) {
                        minAbs = abs;
                        pos = i;
                    }
                }
                result[idx++] = r.get(pos).id;
            }

        }
        return result;
    }

    public static void main(String[] args) {
        Q1847 q = new Q1847();
        int[][] rooms = {{2, 2}, {1, 2}, {3, 2}};
        int[][] queries = {{3, 1}, {3, 3}, {5, 2}};
        System.out.println(Arrays.toString(q.closestRoom(rooms, queries)));
    }
}
