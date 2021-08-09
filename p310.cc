// 最小高度树
// 思路: bfs或者dfs求某节点作为树根时的深度
// TODO: 超时:P

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using std::cout;
using std::endl;
using std::list;
using std::vector;

class Solution {

  private:
    vector<vector<int>> graph;
    vector<int> marked;

    int dfs(vector<vector<int>> &g, int start, int &height) {
        if (marked[start] == 1)
            return height;

        height += 1;
        marked[start] = 1;

        int maxH = 0;
        for (auto next : graph[start]) {
            int currentH = dfs(g, next, height);
            if (currentH > maxH)
                maxH = currentH;
        }

        height -= 1;
        return maxH;
    }

    int bfs(vector<vector<int>> &g, int start) {
        int height = 0;
        list<int> queue = {start};

        while (!queue.empty()) {
            int n = queue.size();
            for (int i = 0; i < n; ++i) {
                int node = queue.front();
                queue.pop_front();
                marked[node] = 1;
                for (auto next : g[node]) {
                    if (marked[next] == 0)
                        queue.push_back(next);
                }
            }
            height += 1;
        }

        return height;
    }

  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {

        // 边界情况
        if (n == 1)
            return {0};

        vector<int> res;
        int minHeight = n + 1;

        marked.resize(n, 0);
        graph.resize(n, vector<int>());

        // 构造无向图
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
            int height = 0;
            // int currentMin = dfs(graph, i, height);
            int currentMin = bfs(graph, i);

            if (currentMin < minHeight) {
                minHeight = currentMin;
                res.clear();
                res.push_back(i);
            } else if (currentMin == minHeight) {
                res.push_back(i);
            }

            std::fill(marked.begin(), marked.end(), 0);
        }

        return res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    int n = 4;
    auto res = s.findMinHeightTrees(n, edges);
    return 0;
}