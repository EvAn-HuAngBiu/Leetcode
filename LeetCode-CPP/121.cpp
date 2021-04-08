#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(vector<int>& prices) {
    vector<int> st;
    prices.emplace_back(-1);
    int prof = 0, size = prices.size();
    for (int i = 0; i < size; i++) {
        while (!st.empty() && st.back() > prices[i]) {
            prof = max(prof, st.back() - st.front());
            st.pop_back();
        }
        st.emplace_back(prices[i]);
    }
    return prof;
}

int main()
{
    vector<int> v = {7,1,5,3,6,4};
    cout << maxProfit(v) << endl;
    return 0;
}