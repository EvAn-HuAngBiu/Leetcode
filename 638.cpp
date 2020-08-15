#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    vector<int> price;
    vector<vector<int>> special;
    int amount;
public:
    int singleBuy(const vector<int>& need) {
        int sum = 0;
        for (int i = 0; i < amount; ++i) {
            sum += price[i] * need[i];
        }
        return sum;
    }

    int dfs(vector<int>& need) {
        int current = singleBuy(need);
        for (auto& s : special) {
            bool flag = true;
            for (int i = 0; i < amount; ++i) {
                need[i] -= s[i];
                if (need[i] < 0) {
                    flag = false;
                }
            }
            if (flag) {
                current = min(current, s[amount] + dfs(need));
            }
            for (int i = 0; i < amount; ++i) {
                need[i] += s[i];
            }
        }
        return current;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        this->price = price;
        this->special = special;
        amount = needs.size();
        return dfs(needs);
    }
};

int main()
{
    vector<int> price;
    vector<vector<int>> special;
    vector<int> needs;
    int n,m;
    cin>>n;
    int p,need;
    for(int i=0; i<n; i++)
    {
        cin>>p;
        price.push_back(p);
    }
    for(int i=0; i<n; i++)
    {
        cin>>need;
        needs.push_back(need);
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        vector<int> oneSpecial;
        int qty;
        for(int j=0; j<n; j++)
        {
            cin>>qty;
            oneSpecial.push_back(qty);
        }
        int amount;
        cin>>amount;
        oneSpecial.push_back(amount);
        special.push_back(oneSpecial);
    }

    int res=Solution().shoppingOffers(price, special, needs);
    cout<<res<<endl;
    return 0;
}