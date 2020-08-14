#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

class Solution
{
private:
    unordered_map<string, multiset<string>> graph;
    unordered_map<string, multiset<string>> visited;
    vector<string> result;
    int n;

public:
    // void dfs(string city)
    // {
    //     if (result.size() == n)
    //     {
    //         return;
    //     }
    //     for (auto &cities : graph[city])
    //     {
    //         if (visited[city].count(cities) != graph[city].count(cities)) {
    //             result.emplace_back(cities);
    //             visited[city].insert(cities);
    //             dfs(cities);
    //             if (result.size() == n)
    //             {
    //                 return;
    //             }
    //             visited[city].erase(cities);
    //             result.pop_back();
    //         }
    //     }
    // }

    // vector<string> findItinerary(vector<vector<string>> &tickets)
    // {
    //     n = tickets.size() + 1;
    //     for (auto &ticket : tickets)
    //     {
    //         graph[ticket[0]].insert(ticket[1]);
    //     }
    //     result.emplace_back("JFK");
    //     for (auto &begin : graph["JFK"])
    //     {
    //         result.emplace_back(begin);
    //         visited["JFK"].insert(begin);
    //         dfs(begin);
    //         if (result.size() == n)
    //         {
    //             return result;
    //         }
    //         visited["JFK"].erase(begin);
    //         result.pop_back();
    //     }
    //     return result;
    // }
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> ump;

        for (auto &vec : tickets)
            ump[vec[0]].push(vec[1]);

        dfs(ump, "JFK");
        return ans;
    }

    void dfs(unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> &ump, string curr)
    {
        while (ump.find(curr) != ump.end() && ump[curr].size() > 0)
        {
            string next = ump[curr].top();
            ump[curr].pop();
            dfs(ump, next);
        }
        ans.insert(ans.begin(), curr);
    }
};

int main()
{
    vector<vector<string>> vv = {{"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"}, {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"}, {"ANU", "TIA"}, {"JFK", "TIA"}};
    vector<string> result = Solution().findItinerary(vv);
    for (auto &s : result)
    {
        cout << s << endl;
    }
    return 0;
}