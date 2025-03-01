#include "../BinaryTreeUtil/binary_tree_util.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int countNodes(TreeNode *root)
    {
        return 0;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, -1, 7};

    TreeNode *root = BinaryTreeUtil::buildTree(nums);

    std::cout << "Print Tree: " << std::endl;
    BinaryTreeUtil::printTree(root);

    BinaryTreeUtil::deleteTree(root);

    return 0;
}