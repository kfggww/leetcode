#include <list>
#include <vector>
using std::list;
using std::vector;

struct Position {
    Position(int i, int j) : row(i), col(j) {}
    int row;
    int col;
};

/**
 * @brief 使用dfs找到一个‘O’形成的区域， 之后判断区域是否满足条件，
 * 若满足则填充‘X’
 *
 */
class Solution {
  public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();

        marked.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {

                    dfs(board, i, j);

                    if (!area.empty() && isValidArea(board)) {
                        for (auto pos : area)
                            board[pos.row][pos.col] = 'X';
                    } else {
                        for (auto pos : area)
                            marked[pos.row][pos.col] = 0;
                    }
                }
                area.clear();
            }
        }
    }

    // 填充区域，要求board[i][j] == 'O'
    void dfs(vector<vector<char>> &board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            marked[i][j] == 1 || board[i][j] != 'O')
            return;

        marked[i][j] = 1;
        area.push_back({i, j});

        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }

    // 检查当前的area是否是被‘X’包围的合法区域
    bool isValidArea(vector<vector<char>> &board) {
        if (area.empty())
            return false;

        for (auto pos : area) {
            if (!surroundedByX(board, pos.row, pos.col))
                return false;
        }

        return true;
    }

    bool surroundedByX(vector<vector<char>> &board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != 'O')
            return false;

        int m = board.size();
        int n = board[0].size();

        int counter1 = 1, counter2 = 1;
        for (int k = 0; k < n; ++k) {
            if (k < j && board[i][k] == 'X')
                counter1 -= 1;
            else if (k > j && board[i][k] == 'X')
                counter2 -= 1;
        }

        if (counter1 > 0 || counter2 > 0)
            return false;

        counter1 = 1;
        counter2 = 1;

        for (int k = 0; k < m; ++k) {
            if (k < i && board[k][j] == 'X')
                counter1 -= 1;
            else if (k > i && board[k][j] == 'X')
                counter2 -= 1;
        }

        return counter1 <= 0 && counter2 <= 0;
    }

  private:
    vector<vector<int>> marked;
    list<Position> area;
};