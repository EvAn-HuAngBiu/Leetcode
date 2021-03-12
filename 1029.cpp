#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int CalcCost(vector<vector<int>>& costs) {
        vector<int> delta(costs.size());
        int sum = 0, size = costs.size();
        for (int i = 0; i < size; ++i) {
            // 全去A的总费用
            sum += costs[i][0];
            // 去B比去A便宜的费用
            delta[i] = costs[i][1] - costs[i][0];
        }
        sort(delta.begin(), delta.end());
        for (int i = 0; i < size / 2; ++i) {
            sum += delta[i];
        }
        return sum;
    }
};

int main()
{
    int N;
    vector<vector<int> > costs;
    cin>>N;
    int costA,costB;
    for(int i=0; i<2*N; i++)
    {
        cin>>costA>>costB;
        vector<int> onePerson;
        onePerson.push_back(costA);
        onePerson.push_back(costB);
        costs.push_back(onePerson);
    }
    int res=Solution().CalcCost(costs);
    cout<<res<<endl;
}