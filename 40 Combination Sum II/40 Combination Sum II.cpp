#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int>         com;

  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size());
        sort(candidates.begin(), candidates.end());
        backtracking(0, 0, candidates, target, used);
        return res;
    }

  private:
    void backtracking(int start, int sum, vector<int> &nums, int targetSum, vector<bool> &used)
    {
        if (sum > targetSum)
            return;
        if (sum == targetSum) {
            res.push_back(com);
        }
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            if (sum + nums[i] > targetSum)
                break;
            used[i] = true;
            com.push_back(nums[i]);
            backtracking(i + 1, sum + nums[i], nums, targetSum, used);
            com.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    Solution s;
    // Input: candidates = [10,1,2,7,6,1,5], target = 8
    // vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    // int         target     = 8;

    // vector<int> candidates = {1, 2};
    // int         target     = 4;

    vector<int> candidates = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int         target     = 30;
    auto        res        = s.combinationSum2(candidates, target);
    for (auto &v : res) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    // Output:
    // [
    // [1,1,6],
    // [1,2,5],
    // [1,7],
    // [2,6]
    // ]

    return 0;
}