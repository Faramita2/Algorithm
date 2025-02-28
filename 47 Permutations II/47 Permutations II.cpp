#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int>         path;

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
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
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
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

    // Input: nums = [1,1,2]
    vector<int> nums1 = {1, 1, 2};
    auto        res1  = s.permuteUnique(nums1);
    for (auto &v : res1) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    s.clear();
    // Output:
    // [[1,1,2],
    // [1,2,1],
    // [2,1,1]]

    // Input: nums = [1,2,3]
    vector<int> nums2 = {1, 2, 3};
    auto        res2  = s.permuteUnique(nums2);
    for (auto &v : res2) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    s.clear();
    // Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    return 0;
}