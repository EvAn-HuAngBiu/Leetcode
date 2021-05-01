package base.offer;

import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q690
 *
 * @author evan
 * @date 2021/5/1
 */
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
}

public class Q690 {
    private Employee[] importantce = new Employee[2001];

    private int queryImportance(int id) {
        int sum = importantce[id].importance;
        for (Integer i : importantce[id].subordinates) {
            sum += queryImportance(i);
        }
        return sum;
    }

    public int getImportance(List<Employee> employees, int id) {
        for (Employee e : employees) {
            importantce[e.id] = e;
        }
        return queryImportance(id);
    }
}
