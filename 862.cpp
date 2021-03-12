#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

// struct Node {
//     int val;
//     int time;
//     Node() {time = 1;}
//     Node(int val, int time = 1) : val(val), time(time) {}
// };

// bool cmp(const Node& a, const Node& b) {
//     return a.time < b.time;
// }

// 错解：题目要求的子数组连续，本解法不连续
// int shortestSubarray(vector<int>& A, int K) {
//     vector<Node> window;
//     for (int i : A) {
//         int pre = window.size();
//         Node cur(i);
//         window.push_back(i);
//         for (int j = 0; j < pre; j++) {
//             Node added(window[j].val + i, window[j].time + 1);
//             window.push_back(added);
//         }
//     }
//     sort(window.begin(), window.end(), cmp);
//     for (Node i : window) {
//         if (i.val >= K) {
//             return i.time;
//         }
//     }
//     return -1;
// }

int shortestSubarray(vector<int>& A, int K) {
    // 首部添加0
    vector<int> sum = {0};
    // 计算前缀和
    for (int i = 0; i < A.size(); i++) {
        sum.push_back(*sum.rbegin() + A[i]);
    }
    // 双端队列
    deque<int> q;
    // 首部添加0
    q.push_back(0);
    int min = INT_MAX;
    for (int i = 1; i < sum.size(); i++) {
        // 队列尾的前缀和大于当前处理的前缀和则舍弃，因为其长度也更长
        while (!q.empty() && sum[i] < sum[q.back()]) {
            q.pop_back();
        }
        // 判断当前前缀长度
        while (!q.empty() && sum[i] - sum[q.front()] >= K) {
            min = (min < i - q.front() ? min : i - q.front());
            q.pop_front();
        }
        q.push_back(i);
    }
    return min == INT_MAX ? -1 : min;
}

int main()
{
    vector<int> v = {-28,81,-20,28,-29};
    cout << shortestSubarray(v, 89) << endl;
    return 0;
}