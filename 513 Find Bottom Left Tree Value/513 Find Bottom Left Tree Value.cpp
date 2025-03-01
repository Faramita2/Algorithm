#include "../BinaryTreeUtil/binary_tree_util.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int findBottomLeftValue(TreeNode *root)
    {
        if (root == nullptr)
            return -1;

        int maxDepth        = -1;
        int bottomLeftValue = 0;

        dfs(root, 0, maxDepth, bottomLeftValue);

        return bottomLeftValue;
    }

  private:
    void dfs(TreeNode *node, int depth, int &maxDepth, int &bottomLeftValue)
    {
        if (node == nullptr)
            return;

        if (depth > maxDepth) {
            maxDepth        = depth;
            bottomLeftValue = node->val;
        }

        dfs(node->left, depth + 1, maxDepth, bottomLeftValue);
        dfs(node->right, depth + 1, maxDepth, bottomLeftValue);
    }
};

int main()
{
    Solution s;

    // Input: root = [2,1,3]
    vector<int> nums1 = {2, 1, 3};
    TreeNode   *root1 = BinaryTreeUtil::buildTree(nums1);
    BinaryTreeUtil::printTree(root1);
    auto res1 = s.findBottomLeftValue(root1);
    cout << "Res1: " << res1 << endl;
    // Output: 1

    // Input: root = [1,2,3,4,null,5,6,null,null,7]
    vector<int> nums2 = {1, 2, 3, 4, -1, 5, 6, -1, -1, 7};
    TreeNode   *root2 = BinaryTreeUtil::buildTree(nums2);
    BinaryTreeUtil::printTree(root2);
    auto res2 = s.findBottomLeftValue(root2);
    cout << "Res2: " << res2 << endl;
    // Output: 7

    // Input: root = [1,-1, 1]
    vector<int> nums3 = {1, -1, 1};
    TreeNode   *root3 = BinaryTreeUtil::buildTree(nums3);
    BinaryTreeUtil::printTree(root3);
    auto res3 = s.findBottomLeftValue(root3);
    cout << "Res3: " << res3 << endl;
    // Output: 1

    return 0;
}