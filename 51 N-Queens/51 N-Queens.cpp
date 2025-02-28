#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<string>> res;

  public:
    vector<vector<string>> solveNQueens(int n)
    {
        string         row(n, '.');
        vector<string> board(n, row);
        backtracking(0, n, board);
        return res;
    }

    void clear()
    {
        res.clear();
    }

  private:
    void backtracking(int row, int n, vector<string> &board)
    {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q';
                backtracking(row + 1, n, board);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string> &board)
    {
        int n = board.size();

        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // left top
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        // right top
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    // Input: n = 4
    int  n1   = 4;
    auto res1 = s.solveNQueens(n1);
    for (auto &v : res1) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    s.clear();
    // Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

    // Input: n = 1
    int  n2   = 1;
    auto res2 = s.solveNQueens(n2);
    for (auto &v : res2) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    // Output: [["Q"]]

    return 0;
}