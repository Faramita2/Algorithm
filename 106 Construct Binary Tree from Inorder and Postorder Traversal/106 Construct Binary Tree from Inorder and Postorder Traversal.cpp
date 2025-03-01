#include "../BinaryTreeUtil/binary_tree_util.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int start, int end)
    {
        if (postorder.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(postorder.back());
        if (postorder.size() == 1)
            return root;
        int index;
        for (index = start; index < end; index++) {
            if (inorder[index] == root->val)
                break;
        }

        root->left = build(inorderLeft, inorderRight, );
    }
};

int main()
{
    Solution s;

    // Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    vector<int> inorder1   = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};
    TreeNode   *root1      = s.buildTree(inorder1, postorder1);
    BinaryTreeUtil::printTree(root1);
    // Output: [3,9,20,null,null,15,7]

    // Input: inorder = [-1], postorder = [-1]
    vector<int> inorder2   = {-1};
    vector<int> postorder2 = {-1};
    TreeNode   *root2      = s.buildTree(inorder2, postorder2);
    BinaryTreeUtil::printTree(root2);
    // Output: [-1]

    return 0;
}