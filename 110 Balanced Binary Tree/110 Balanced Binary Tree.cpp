#include "../BinaryTreeUtil/binary_tree_util.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) != -1;
    }

  private:
    int getHeight(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int leftHeight  = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        if (leftHeight == -1 || rightHeight == -1)
            return -1;
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        return 1 + max(leftHeight, rightHeight);
    }
};

int main()
{
    Solution s;

    // Input: root = [3,9,20,null,null,15,7]
    vector<int> nums1 = {3, 9, 20, -1, -1, 15, 7};
    TreeNode   *root1 = BinaryTreeUtil::buildTree(nums1);
    auto        res1  = s.isBalanced(root1);
    cout << "Res1: " << res1 << endl;
    // Output: true

    // Input: root = [1,2,2,3,3,null,null,4,4]
    vector<int> nums2 = {1, 2, 2, 3, 3, -1, -1, 4, 4};
    TreeNode   *root2 = BinaryTreeUtil::buildTree(nums2);
    auto        res2  = s.isBalanced(root2);
    cout << "Res2: " << res2 << endl;
    // Output: false

    // Input: root = []
    vector<int> nums3 = {};
    TreeNode   *root3 = BinaryTreeUtil::buildTree(nums3);
    auto        res3  = s.isBalanced(root3);
    cout << "Res3: " << res3 << endl;
    // Output: true

    return 0;
}