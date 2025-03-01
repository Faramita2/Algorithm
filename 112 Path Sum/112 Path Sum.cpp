#include "../BinaryTreeUtil/binary_tree_util.h"
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        return findSum(root, 0, targetSum);
    }

  private:
    bool findSum(TreeNode *node, int preSum, int targetSum)
    {
        if (node == nullptr)
            return false;

        int sum = preSum + node->val;
        if (node->left == nullptr && node->right == nullptr && sum == targetSum)
            return true;

        return findSum(node->left, sum, targetSum) || findSum(node->right, sum, targetSum);
    }
};

int main()
{
    Solution s;

    // Input: root = [5,4,8,11,-1,13,4,7,2,-1,-1,-1,1], targetSum = 22
    vector<int> nums1      = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    int         targetSum1 = 22;
    TreeNode   *root1      = BinaryTreeUtil::buildTree(nums1);
    BinaryTreeUtil::printTree(root1);
    auto res1 = s.hasPathSum(root1, targetSum1);
    assert(true == res1);
    // Output: true

    // Input: root = [1,2,3], targetSum = 5
    vector<int> nums2      = {1, 2, 3};
    int         targetSum2 = 5;
    TreeNode   *root2      = BinaryTreeUtil::buildTree(nums2);
    BinaryTreeUtil::printTree(root2);
    auto res2 = s.hasPathSum(root2, targetSum2);
    assert(false == res2);
    // Output: false

    // Input: root = [], targetSum = 0
    vector<int> nums3      = {};
    int         targetSum3 = 0;
    TreeNode   *root3      = BinaryTreeUtil::buildTree(nums3);
    BinaryTreeUtil::printTree(root3);
    auto res3 = s.hasPathSum(root3, targetSum3);
    assert(false == res3);
    // Output: false

    return 0;
}