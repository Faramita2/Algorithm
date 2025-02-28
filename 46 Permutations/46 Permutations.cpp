#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int>         path;

  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }

    void clear()
    {
        res.clear();
    }

  private:
    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
            res.push_back(path);
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    Solution s;

    // Input: nums = [1,2,3]
    vector<int> nums1 = {1, 2, 3};
    auto        res1  = s.permute(nums1);
    for (auto &v : res1) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    s.clear();
    // Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    // Input: nums = [0,1]
    vector<int> nums2 = {0, 1};
    auto        res2  = s.permute(nums2);
    for (auto &v : res2) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    s.clear();
    // Output: [[0,1],[1,0]]

    // Input: nums = [1]
    vector<int> nums3 = {1};
    auto        res3  = s.permute(nums3);
    for (auto &v : res3) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    // Output: [[1]]

    return 0;
}