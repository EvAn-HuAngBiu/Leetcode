package base;

import java.util.HashMap;
import java.util.Map;

/**
 * Project: LeetCode-Java
 * File: Q208
 *
 * @author evan
 * @date 2021/4/14
 */
class Trie {
    class TrieNode {
        char val;
        boolean last = false;
        TrieNode[] next;

        public TrieNode(char val) {
            this.val = val;
            this.next = new TrieNode[26];
        }
    }
    TrieNode[] root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode[26];
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        char[] cur = word.toCharArray();
        int len = cur.length;
        TrieNode[] p = root;
        for (int i = 0; i < len; i++) {
            char t = cur[i];
            if (p[t - 'a'] == null) {
                p[t - 'a'] = new TrieNode(t);
            }
            if (i == len - 1) {
                p[t - 'a'].last = true;
            }
            p = p[t - 'a'].next;
        }
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        char[] cur = word.toCharArray();
        TrieNode[] p = root;
        boolean isLast = false;
        for (char t : cur) {
            if (p[t - 'a'] == null) {
                return false;
            }
            isLast = p[t - 'a'].last;
            p = p[t - 'a'].next;
        }
        return isLast;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        char[] cur = prefix.toCharArray();
        TrieNode[] p = root;
        for (char t : cur) {
            if (p[t - 'a'] == null) {
                return false;
            }
            p = p[t - 'a'].next;
        }
        return true;
    }
}

public class Q208 {
    public static void main(String[] args) {
        Trie t = new Trie();
        t.insert("apple");
        System.out.println(t.search("apple"));
        System.out.println(t.search("app"));
        System.out.println(t.startsWith("app"));
        t.insert("app");
        System.out.println(t.search("app"));
        System.out.println(t.startsWith("app"));
    }
}
