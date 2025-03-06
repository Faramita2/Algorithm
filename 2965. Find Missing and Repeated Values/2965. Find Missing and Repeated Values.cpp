#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int         n = grid.size();
        vector<int> m(n * n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[grid[i][j] - 1]++;
            }
        }
        int repeteated, missed;
        for (int i = 0; i < m.size(); i++) {
            if (m[i] == 2)
                repeteated = i + 1;
            if (m[i] == 0)
                missed = i + 1;
        }

        return {repeteated, missed};
    }
};

int main()
{
    Solution solution;

    // Input: grid = [[1,3],[2,2]]
    vector<vector<int>> grid1 = {{1, 3}, {2, 2}};
    auto                res1  = solution.findMissingAndRepeatedValues(grid1);
    for (auto i : res1) {
        cout << i << " ";
    }
    cout << endl;
    // Output: [2,4]

    // Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
    vector<vector<int>> grid2 = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    auto                res2  = solution.findMissingAndRepeatedValues(grid2);
    for (auto i : res2) {
        cout << i << " ";
    }
    cout << endl;
    // Output: [9,5]

    return 0;
}
