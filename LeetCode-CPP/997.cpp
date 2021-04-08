#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    struct Node {
        int inner = 0;
        int outer = 0;
        Node() {}
        Node(int inner, int outer) : inner(inner), outer(outer) {}
    };

    int findJudge(int N, vector<vector<int>>& trust) {
        if (N == 1) {
            return 1;
        }
        map<int, Node> graph;
        int rlen = trust.size();
        for (int i = 0; i < rlen; i++) {
            int a = trust[i][0], b = trust[i][1];
            if (graph.find(a) == graph.end()) {
                Node na = Node(0, 1);
                graph[a] = na;
            } else {
                graph[a].outer++;
            }

            if (graph.find(b) == graph.end()) {
                Node nb = Node(1, 0);
                graph[b] = nb;
            } else {
                graph[b].inner++;
            }
        }
        for (auto it = graph.begin(); it != graph.end(); it++) {
            if (it->second.inner == N - 1 && it->second.outer == 0) {
                return it->first;
            }
        }
        return -1;
    }
};

int main()
{
    int N,M;
    vector<vector<int> > trust;
    cin>>N>>M;
    int p1,p2;
    for(int i=0; i<M; i++)
    {
        cin>>p1>>p2;
        vector<int> oneTrust;
        oneTrust.push_back(p1);
        oneTrust.push_back(p2);
        trust.push_back(oneTrust);
    }
    int res=Solution().findJudge(N, trust);
    cout<<res<<endl;
}