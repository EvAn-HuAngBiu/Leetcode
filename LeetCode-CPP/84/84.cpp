#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int largestRectangleArea(vector<int>& heights) {
    heights.emplace_back(-1);
    vector<int> st;
    int size = heights.size(), area = 0, top;
    for (int i = 0; i < size; i++) {
        if (st.empty() || heights[st.back()] <= heights[i]) {
            st.push_back(i);
        } else {
            while (!st.empty() && heights[st.back()] > heights[i]) {
                top = st.back();
                st.pop_back();
                area = max(area, heights[top] * (i - top));
            }
            heights[top] = heights[i];
            st.push_back(top);
        }
    }
    return area;
}

int main()
{
    vector<int> v = {2,1,5,6,2,3};
    cout << largestRectangleArea(v) << endl;
    return 0;
}