package base;

import java.util.*;
import java.util.stream.Collectors;

/**
 * Project: LeetCode-Java
 * File: Q692
 *
 * @author evan
 * @date 2021/5/20
 */
public class Q692 {
    static class CountString {
        private String val;
        private int time = 0;

        public CountString(String val) {
            this.val = val;
        }

        public void increase() {
            this.time++;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            CountString that = (CountString) o;
            return time == that.time;
        }

        @Override
        public int hashCode() {
            return Objects.hash(time);
        }
    }

    public static List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> counter = new HashMap<>(words.length);
        for (String word : words) {
            counter.put(word, counter.getOrDefault(word, 0) + 1);
        }
        return counter.entrySet().stream().sorted((o1, o2) -> {
            if (o1.getValue().equals(o2.getValue())) {
                return o1.getKey().compareTo(o2.getKey());
            }
            return o2.getValue().compareTo(o1.getValue());
        }).limit(k).map(Map.Entry::getKey).collect(Collectors.toList());
    }

    public static void main(String[] args) {
        String[] words = {"i", "love", "leetcode", "i", "love", "coding"};
        System.out.println(topKFrequent(words, 2));
    }
}
