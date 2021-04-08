#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct Node {
    int data;
    int time;
    Node() {time = 0;}
    Node(int data, int time) : data(data), time(time) {}
};

bool cmp(const Node& a, const Node& b) {
    return a.time > b.time;
}

int leastInterval(vector<char>& tasks, int n) {
    Node cnt[26];
    deque<int> ava;
    for (char c : tasks) {
        int index = c - 'A';
        cnt[index].data = index;
        ++cnt[index].time;
    }
    sort(begin(cnt), end(cnt), cmp);
    for (int i = 0; i < 26; i++) {
        if (cnt[i].time > 0) {
            ava.push_back(i);
        } else {
            break;
        }
    }
    int call, time = 0;
    while (!ava.empty()) {
        call = 0;
        while (!ava.empty() && call <= n) {
            int cur = ava.front();
            --cnt[cur].time;
            ava.pop_front();
            ++call;
        }
        time += call;
        sort(begin(cnt), end(cnt), cmp);
        if (cnt[0].time > 0 && call <= n) {
            time += n - call + 1;
        }
        ava.clear();
        for (int i = 0; i < 26; i++) {
            if (cnt[i].time > 0) {
                ava.push_back(i);
            } else {
                break;
            }
        }
    }
    return time;
}

int main()
{
    vector<char> c = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << leastInterval(c, 0) << endl;
    return 0;
}