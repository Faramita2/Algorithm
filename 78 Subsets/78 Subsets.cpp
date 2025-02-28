#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res = {};
    vector<int>         path;

  public:
    vector<vector<int>> subsets(const vector<int> &nums)
    {
        backtracking(0, nums);
        return res;
    }

    void clear()
    {
        res.clear();
    }

  private:
    void backtracking(int startIndex, const vector<int> &nums)
    {
        res.push_back(path);
        if (startIndex == nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;

    // Input: nums = [1,2,3]
    vector<int> nums1 = {1, 2, 3};
    auto        res1  = s.subsets(nums1);
    for (auto &v : res1) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    s.clear();
    // Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    // Input: nums = [0]
    vector<int> nums2 = {0};
    auto        res2  = s.subsets(nums2);

    for (auto &v : res2) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    // Output: [[],[0]]

    return 0;
}