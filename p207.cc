#include <vector>
using std::vector;

class Solution {

  private:
    vector<vector<int>> edges;
    vector<int> marked;
    bool valid = true;

  private:
    // dfs遍历整个图, 并给访问过的节点涂色, 0: 未访问, 1: 访问中, 2: 访问过
    void dfs(int s) {
        marked[s] = 1;
        for (auto next : edges[s]) {
            if (marked[next] == 0) {
                dfs(next);
                if (valid == false)
                    return;
            } else if (marked[next] == 1) {
                valid = false;
                return;
            }
        }
        marked[s] = 2;
    }

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        marked.resize(numCourses, 0);

        // 初始化图
        for (auto item : prerequisites) {
            edges[item[1]].push_back(item[0]);
        }

        // 遍历图
        for (int i = 0; i < numCourses; ++i) {
            if (marked[i] == 0)
                dfs(i);
            if (valid == false)
                return false;
        }

        return true;
    }
};