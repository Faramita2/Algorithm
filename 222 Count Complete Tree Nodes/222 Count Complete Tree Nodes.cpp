#include "../BinaryTreeUtil/binary_tree_util.h"
#include <iostream>
#include <queue>
using namespace std;

class Solution
{
  public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int       leftHeight = 0, rightHeight = 0;
        TreeNode *left = root, *right = root;
        while (left) {
            left = left->left;
            leftHeight++;
        }

        while (right) {
            right = right->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{
    Solution s;

    // Input: root = [1,2,3,4,5,6]
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    TreeNode        *root1 = BinaryTreeUtil::buildTree(nums1);
    std::cout << "Print Tree: " << std::endl;
    BinaryTreeUtil::printTree(root1);

    auto res1 = s.countNodes(root1);
    cout << "Root1 has " << res1 << endl;
    BinaryTreeUtil::deleteTree(root1);
    // Output: 6

    // Input: root = []
    std::vector<int> nums2 = {};
    TreeNode        *root2 = BinaryTreeUtil::buildTree(nums2);
    std::cout << "Print Tree: " << std::endl;
    BinaryTreeUtil::printTree(root2);

    auto res2 = s.countNodes(root2);
    cout << "Root2 has " << res2 << endl;
    BinaryTreeUtil::deleteTree(root2);
    // Output: 0

    // Input: root = [1]
    std::vector<int> nums3 = {1};
    TreeNode        *root3 = BinaryTreeUtil::buildTree(nums3);
    std::cout << "Print Tree: " << std::endl;
    BinaryTreeUtil::printTree(root3);

    auto res3 = s.countNodes(root3);
    cout << "Root3 has " << res3 << endl;
    BinaryTreeUtil::deleteTree(root3);
    // Output: 1

    return 0;
}