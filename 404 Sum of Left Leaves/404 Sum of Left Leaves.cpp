#include "../BinaryTreeUtil/binary_tree_util.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        return postOrder(root);
    }

  private:
    int addLeft(TreeNode *node)
    {
        int sum = 0;

        if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
            sum += node->left->val;
        } else if (node->left != nullptr) {
            sum += addLeft(node->left);
        }

        if (node->right != nullptr) {
            sum += addLeft(node->right);
        }

        return sum;
    }

    int postOrder(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int leftSum  = postOrder(node->left);
        int rightSum = postOrder(node->right);

        int currSum = 0;
        if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
            currSum += node->left->val;
        }

        return leftSum + rightSum + currSum;
    }
};

int main()
{
    Solution s;

    // Input: root = [3,9,20,null,null,15,7]
    vector<int> nums1 = {3, 9, 20, -1, -1, 15, 7};
    TreeNode   *root1 = BinaryTreeUtil::buildTree(nums1);
    BinaryTreeUtil::printTree(root1);
    auto res1 = s.sumOfLeftLeaves(root1);
    cout << "Res1: " << res1 << endl;
    // Output: 24

    // Input: root = [1]
    vector<int> nums2 = {1};
    TreeNode   *root2 = BinaryTreeUtil::buildTree(nums2);
    BinaryTreeUtil::printTree(root2);
    auto res2 = s.sumOfLeftLeaves(root2);
    cout << "Res2: " << res2 << endl;
    // Output: 0

    // Input: root = [1,2,3,4,5]
    vector<int> nums3 = {1, 2, 3, 4, 5};
    TreeNode   *root3 = BinaryTreeUtil::buildTree(nums3);
    BinaryTreeUtil::printTree(root3);
    auto res3 = s.sumOfLeftLeaves(root3);
    cout << "Res3: " << res3 << endl;
    // Output: 4

    return 0;
}