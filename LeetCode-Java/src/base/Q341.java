package base;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q341
 *
 * @author evan
 * @date 2021/3/23
 */
interface NestedInteger {

    // @return true if this NestedInteger holds a single integer, rather than a nested list.
    boolean isInteger();

    // @return the single integer that this NestedInteger holds, if it holds a single integer
    // Return null if this NestedInteger holds a nested list
    Integer getInteger();

    // @return the nested list that this NestedInteger holds, if it holds a nested list
    // Return null if this NestedInteger holds a single integer
    List<NestedInteger> getList();
}

class NestedIntegerImpl implements NestedInteger {
    private Integer num = null;
    private List<NestedInteger> list = null;

    public Integer getNum() {
        return num;
    }

    public void setNum(Integer num) {
        this.num = num;
    }

    public void setList(List<NestedInteger> list) {
        this.list = list;
    }

    @Override
    public boolean isInteger() {
        return num != null;
    }

    @Override
    public Integer getInteger() {
        return isInteger() ? num : null;
    }

    @Override
    public List<NestedInteger> getList() {
        return isInteger() ? null : list;
    }
}

class NestedIterator implements Iterator<Integer> {
    private List<Integer> list;
    private int cnt;

    public NestedIterator(List<NestedInteger> nestedList) {
        list = new ArrayList<>();
        cnt = 0;
        for (NestedInteger i : nestedList) {
            if (i.isInteger()) {
                list.add(i.getInteger());
            } else {
                list.addAll(parseNestedInteger(i));
            }
        }
    }

    private List<Integer> parseNestedInteger(NestedInteger list) {
        List<Integer> result = new ArrayList<>();
        List<NestedInteger> next = list.getList();
        for (NestedInteger i : next) {
            if (i.isInteger()) {
                result.add(i.getInteger());
            } else {
                result.addAll(parseNestedInteger(i));
            }
        }
        return result;
    }

    @Override
    public Integer next() {
        return this.list.get(this.cnt++);
    }

    @Override
    public boolean hasNext() {
        return this.cnt < this.list.size();
    }
}

public class Q341 {
    public static void main(String[] args) {
        // NestedIntegerImpl insideNum1 = new NestedIntegerImpl();
        // insideNum1.setNum(1);
        // NestedIntegerImpl insideNum2 = new NestedIntegerImpl();
        // insideNum2.setNum(1);
        // List<NestedInteger> insideList1 = List.of(insideNum1, insideNum2);
        // NestedIntegerImpl in1 = new NestedIntegerImpl();
        // in1.setList(insideList1);
        //
        // NestedIntegerImpl insideNum3 = new NestedIntegerImpl();
        // insideNum3.setNum(2);
        //
        // NestedIntegerImpl insideNum4 = new NestedIntegerImpl();
        // insideNum4.setNum(1);
        // NestedIntegerImpl insideNum5 = new NestedIntegerImpl();
        // insideNum5.setNum(1);
        // List<NestedInteger> insideList2 = List.of(insideNum4, insideNum5);
        // NestedIntegerImpl in2 = new NestedIntegerImpl();
        // in2.setList(insideList2);
        //
        // List<NestedInteger> rootInside = List.of(in1, insideNum3, in2);
        NestedIntegerImpl insideNum1 = new NestedIntegerImpl();
        insideNum1.setNum(1);

        NestedIntegerImpl in1 = new NestedIntegerImpl();
        NestedIntegerImpl insideNum2 = new NestedIntegerImpl();
        insideNum2.setNum(4);


        NestedIntegerImpl in2 = new NestedIntegerImpl();
        List<NestedInteger> insideList2 = new ArrayList<>();
        NestedIntegerImpl insideNum3 = new NestedIntegerImpl();
        insideNum3.setNum(6);
        insideList2.add(insideNum3);
        in2.setList(insideList2);

        List<NestedInteger> insideList1 = List.of(insideNum2, in2);
        in1.setList(insideList1);


        List<NestedInteger> rootInside = List.of(insideNum1, in1);

        NestedIterator it = new NestedIterator(rootInside);
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }
}
