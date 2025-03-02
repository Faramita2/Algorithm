#include "../BinaryTreeUtil/binary_tree_util.h"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    unordered_map<int, int> m;
    vector<int>             inorder;
    vector<int>             postorder;

  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        this->inorder   = inorder;
        this->postorder = postorder;
        return build(0, inorder.size(), 0, postorder.size());
    }

    TreeNode *build(int inLeft, int inRight, int postLeft, int postRight)
    {
        if (postRight == postLeft)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[postRight - 1]);
        if (postRight - postLeft == 1)
            return root;
        int inMid           = m[root->val];
        int leftSubtreeSize = inMid - inLeft;
        root->left          = build(inLeft, inMid, postLeft, postLeft + leftSubtreeSize);
        root->right         = build(inMid + 1, inRight, postLeft + leftSubtreeSize, postRight - 1);
        return root;
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