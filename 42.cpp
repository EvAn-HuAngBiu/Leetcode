#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    // 栈记录所有可用的左边界
    stack<int> left;
    int result = 0;
    for (int i = 0; i < height.size(); i++) {
        while (!left.empty() && height[i] > height[left.top()]) {
            // 当前底部
            int bottom = left.top();
            left.pop();
            if (left.empty()) {
                // 没有左边界，不能装水
                break;
            }
            // 当前左边界
            int currentLeft = left.top();
            // 木桶效应，深度取决于短的木板
            // 可装水空间 = (右边界索引-左边界索引-1) * (深度)
            result += (i - currentLeft - 1) * (min(height[i], height[currentLeft]) - height[bottom]);
        }
        left.push(i);
    }
    return result;
}


int main()
{
    vector<int> v = {0, 2, 1, 0, 1, 2};
    cout << trap(v) << endl;
    return 0;
}