#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return midNode(nums, 0, nums.size());
    }

    TreeNode *midNode(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return nullptr;

        int  mid  = low + (high - low) / 2;
        auto root = new TreeNode(nums[mid]);

        root->left  = midNode(nums, low, mid);
        root->right = midNode(nums, mid + 1, high);

        return root;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [-10,-3,0,5,9]
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    auto        root1 = solution.sortedArrayToBST(nums1);
    BinaryTreeUtil::printTree(root1);
    // Output: [0,-3,9,-10,null,5]

    // Input: nums = [1,3]
    vector<int> nums2 = {1, 3};
    auto        root2 = solution.sortedArrayToBST(nums2);
    BinaryTreeUtil::printTree(root2);
    // Output: [3,1]

    return 0;
}