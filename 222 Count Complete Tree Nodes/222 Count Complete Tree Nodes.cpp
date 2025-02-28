#include <iostream>
#include <vector>
#include "../BinaryTreeUtil/binary_tree_util.h"
using namespace std;

class Solution {
public:
	int countNodes(TreeNode* root) {
		return 0;
	}
};

int main()
{
    // 测试用例
    std::vector<int> nums = { 1, 2, 3, 4, 5, -1, 7 };

    // 构建二叉树
    TreeNode* root = BinaryTreeUtil::buildTree(nums);

    // 打印二叉树
    std::cout << "构建的二叉树：" << std::endl;
    BinaryTreeUtil::printTree(root);

    // 释放内存
    BinaryTreeUtil::deleteTree(root);

    return 0;
}