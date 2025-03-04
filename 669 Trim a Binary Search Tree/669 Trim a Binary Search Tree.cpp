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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val < low) {
            return trimBST(root->right, low, high);
        }

        if (root->val > high) {
            return trimBST(root->left, low, high);
        }

        root->left  = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [1,0,2], low = 1, high = 2
    vector<int> nums1       = {1, 0, 2};
    int         low1        = 1;
    int         high1       = 2;
    auto        root1       = BinaryTreeUtil::buildTree(nums1);
    auto        trimedRoot1 = solution.trimBST(root1, low1, high1);
    BinaryTreeUtil::printTree(trimedRoot1);
    // Output: [1,-1,2]

    // Input: root = [3,0,4,-1,2,-1,-1,1], low = 1, high = 3
    vector<int> nums2       = {3, 0, 4, -1, 2, -1, -1, 1};
    int         low2        = 1;
    int         high2       = 3;
    auto        root2       = BinaryTreeUtil::buildTree(nums2);
    auto        trimedRoot2 = solution.trimBST(root2, low2, high2);
    BinaryTreeUtil::printTree(trimedRoot2);
    // Output: [3,2,-1,1]

    return 0;
}