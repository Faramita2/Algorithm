#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int>         path;

  public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(1, n, 0, 9, k);
        return res;
    }

  private:
    void backtracking(int startIndex, int target, int sum, int length, int size)
    {
        if (sum > target)
            return;
        if (path.size() == size && sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= length - (size - path.size()) + 1; i++) {
            sum += i;
            path.push_back(i);
            backtracking(i + 1, target, sum, length, size);
            sum -= i;
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    auto     res = s.combinationSum3(4, 1);
    for (auto &v : res) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}