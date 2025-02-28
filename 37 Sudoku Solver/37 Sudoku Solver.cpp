#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }

  private:
    bool backtracking(vector<vector<char>> &board)
    {
        int n = board.size();

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] != '.')
                    continue;
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(row, col, num, board)) {
                        board[row][col] = num;
                        if (backtracking(board))
                            return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(int row, int col, char num, vector<vector<char>> &board)
    {
        int n = board.size();

        // duplicate elements in same row or same column
        for (int i = 0; i < n; i++) {
            if (board[row][i] == num || board[i][col] == num)
                return false;
        }
        // each element nearby 3x3 sub-boxes must be unique
        int fixedRowStart = row / 3 * 3;
        int fixedColStart = col / 3 * 3;
        for (int i = fixedRowStart; i < fixedRowStart + 3; i++) {
            for (int j = fixedColStart; j < fixedColStart + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    // Input: board =[
    // 	["5","3",".",".","7",".",".",".","."],
    // 	["6",".",".","1","9","5",".",".","."],
    //	[".","9","8",".",".",".",".","6","."],
    //	["8",".",".",".","6",".",".",".","3"],
    //	["4",".",".","8",".","3",".",".","1"],
    //	["7",".",".",".","2",".",".",".","6"],
    //	[".","6",".",".",".",".","2","8","."],
    // 	[".",".",".","4","1","9",".",".","5"],
    //	[".",".",".",".","8",".",".","7","9"]]
    vector<vector<char>> board1 = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << "The Sudoku problem board is: \n" << endl;
    for (auto &v : board1) {
        for (auto c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
    s.solveSudoku(board1);
    cout << "\nSolved board: \n" << endl;
    for (auto &v : board1) {
        for (auto c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
    // Output: [
    //	["5","3","4","6","7","8","9","1","2"],
    //	["6","7","2","1","9","5","3","4","8"],
    //	["1","9","8","3","4","2","5","6","7"],
    //	["8","5","9","7","6","1","4","2","3"],
    //	["4","2","6","8","5","3","7","9","1"],
    //	["7","1","3","9","2","4","8","5","6"],
    //	["9","6","1","5","3","7","2","8","4"],
    //	["2","8","7","4","1","9","6","3","5"],
    //	["3","4","5","2","8","6","1","7","9"]]

    return 0;
}