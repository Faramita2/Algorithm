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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                auto tmp = root->right;
                delete root;
                return tmp;
            } else if (root->right == nullptr) {
                auto tmp = root->left;
                delete root;
                return tmp;
            } else {
                //        replaced by predecessor
                auto predecessor = findMax(root->left);
                root->val        = predecessor->val;
                root->left       = deleteNode(root->left, predecessor->val);

                //        or replaced by successor
                // auto *successor = findMin(root->right);
                // root->val           = successor->val;
                // root->right         = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }

  private:
    TreeNode *findMin(TreeNode *node)
    {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode *findMax(TreeNode *node)
    {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: root = [5,3,6,2,4,null,7], key = 3
    vector<int> nums1        = {5, 3, 6, 2, 4, -1, 7};
    int         key1         = 3;
    auto        root1        = BinaryTreeUtil::buildTree(nums1);
    auto        deletedRoot1 = solution.deleteNode(root1, key1);
    BinaryTreeUtil::printTree(deletedRoot1);
    // Output: [5,4,6,2,null,null,7]

    // Input: root = [5,3,6,2,4,null,7], key = 0
    vector<int> nums2        = {5, 3, 6, 2, 4, -1, 7};
    int         key2         = 0;
    auto        root2        = BinaryTreeUtil::buildTree(nums2);
    auto        deletedRoot2 = solution.deleteNode(root2, key2);
    BinaryTreeUtil::printTree(deletedRoot2);
    // Output: [5,3,6,2,4,null,7]

    // Input: root = [], key = 0
    vector<int> nums3        = {};
    int         key3         = 0;
    auto        root3        = BinaryTreeUtil::buildTree(nums3);
    auto        deletedRoot3 = solution.deleteNode(root3, key3);
    BinaryTreeUtil::printTree(deletedRoot3);
    // Output: []

    return 0;
}