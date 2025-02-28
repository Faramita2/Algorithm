#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int>         path;

  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(0, nums, used);
        return res;
    }

    void clear()
    {
        res.clear();
    }

  private:
    void backtracking(int startIndex, vector<int> &nums, vector<bool> &used)
    {
        res.push_back(path);

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(i + 1, nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    Solution s;

    // Input: nums = [1,2,2]
    vector<int> nums1 = {1, 2, 2};
    auto        res1  = s.subsetsWithDup(nums1);
    for (auto &v : res1) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    s.clear();
    // Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

    // Input: nums = [0]
    vector<int> nums2 = {0};
    auto        res2  = s.subsetsWithDup(nums2);

    for (auto &v : res2) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    // Output: [[],[0]]

    return 0;
}