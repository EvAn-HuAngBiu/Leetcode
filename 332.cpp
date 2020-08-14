#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
private:
    unordered_map<string, multiset<string>> graph;
    unordered_map<string, multiset<string>> visited;
    vector<string> result;
    int n;

public:
    void dfs(string city)
    {
        if (result.size() == n)
        {
            return;
        }
        for (auto &cities : graph[city])
        {
            if (visited[city].count(cities) != graph[city].count(cities)) {
                result.emplace_back(cities);
                visited[city].insert(cities);
                dfs(cities);
                if (result.size() == n)
                {
                    return;
                }
                visited[city].erase(cities);
                result.pop_back();
            }
        }
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        n = tickets.size() + 1;
        for (auto &ticket : tickets)
        {
            graph[ticket[0]].insert(ticket[1]);
        }
        result.emplace_back("JFK");
        for (auto &begin : graph["JFK"])
        {
            result.emplace_back(begin);
            visited["JFK"].insert(begin);
            dfs(begin);
            if (result.size() == n)
            {
                return result;
            }
            visited["JFK"].erase(begin);
            result.pop_back();
        }
        return result;
    }
};

int main()
{
    vector<vector<string>> vv = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    vector<string> result = Solution().findItinerary(vv);
    for (auto &s : result)
    {
        cout << s << endl;
    }
    return 0;
}