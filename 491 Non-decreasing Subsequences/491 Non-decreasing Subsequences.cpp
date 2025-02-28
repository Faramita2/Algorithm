#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int>         path;

  public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtracking(0, nums);
        return res;
    }

    void clear()
    {
        res.clear();
    }

  private:
    void backtracking(int startIndex, vector<int> &nums)
    {
        if (path.size() >= 2)
            res.push_back(path);

        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back())
                continue;
            if (uset.find(nums[i]) != uset.end())
                continue;
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;

    // Input: nums = [4,6,7,7]
    vector<int> nums1 = {4, 6, 7, 7};
    auto        res1  = s.findSubsequences(nums1);
    for (auto &v : res1) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    s.clear();
    // Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

    // Input: nums = [4,4,3,2,1]
    vector<int> nums2 = {4, 4, 3, 2, 1};
    auto        res2  = s.findSubsequences(nums2);
    for (auto &v : res2) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    s.clear();
    // Output: [[4,4]]

    // Input: nums = [1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 1, 1, 1};

    // auto res3 = s.findSubsequences(nums3);
    // for (auto &v : res3) {
    //     for (int i : v) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}