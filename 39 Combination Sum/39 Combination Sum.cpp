#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int>         com;

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(0, 0, candidates, target);
        return res;
    }

  private:
    void backtracking(int start, int sum, vector<int> &nums, int targetSum)
    {
        if (sum > targetSum)
            return;
        if (sum == targetSum) {
            res.push_back(com);
        }
        for (int i = start; i < nums.size(); i++) {
            if (sum + nums[i] > targetSum) {
                break;
            }
            com.push_back(nums[i]);
            backtracking(i, sum + nums[i], nums, targetSum);
            com.pop_back();
        }
    }
};

int main()
{
    // Input: candidates = [2,3,6,7], target = 7
    Solution    s;
    vector<int> candidates = {2, 3, 6, 7};
    int         target     = 7;
    auto        res        = s.combinationSum(candidates, target);
    for (auto &v : res) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    // Output: [[2,2,3],[7]]
    return 0;
}