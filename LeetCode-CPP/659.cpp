#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int INF = 0x7fffffff;

struct Seq {
    int last;
    int len;
    Seq() {}
    Seq(int last, int len) : last(last), len(len) {}
};

struct cmp {
    bool operator()(const Seq& s1, const Seq& s2) {
        return s1.len < s2.len;
    }
};

bool isPossible(vector<int>& nums) {
    vector<Seq> v;
    v.push_back(Seq(nums[0], 1));
    for (int i = 1; i < nums.size(); i++) {
        int minIndex, minLen = INF, cur = nums[i];
        for (int j = 0; j < v.size(); j++) {
            if (cur == v[j].last + 1 && v[j].len < minLen) {
                minIndex = j;
                minLen = v[j].len;
            }
        }
        if (minLen == INF) {
            v.push_back(Seq(cur, 1));
        } else {
            ++v[minIndex].last;
            ++v[minIndex].len;
        }
    }

    for (const Seq& s : v) {
        if (s.len < 3) {
            return false;
        }
    }
    return true;
}

bool isPossibleAC(vector<int>& nums) {
    map<int, int> counter, tail;
    for (const int& n : nums) {
        ++counter[n];
    }
    for (const int& n : nums) {
        if (counter[n] == 0) {
            continue;
        } else if (tail[n]) {
            --tail[n];
            ++tail[n + 1];
        } else if (counter[n + 1] && counter[n + 2]) {
            --counter[n + 1];
            --counter[n + 2];
            ++tail[n + 3];
        } else {
            return false;
        }
        --counter[n];
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << boolalpha << isPossible2(v) << endl;
    return 0;
}