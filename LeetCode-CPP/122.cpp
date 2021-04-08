#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int curPrice = prices[0], prof = 0, size = prices.size();
    for (int i = 1; i < size; i++) {
        if (prices[i] > curPrice) {
            prof += prices[i] - curPrice;
        }
        curPrice = prices[i];
    }
    return prof;
}

int main()
{
    vector<int> v = {7,1,5,3,6,4};
    cout << maxProfit(v) << endl;
    return 0;
}