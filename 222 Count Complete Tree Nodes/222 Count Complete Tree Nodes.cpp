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
    // ��������
    std::vector<int> nums = { 1, 2, 3, 4, 5, -1, 7 };

    // ����������
    TreeNode* root = BinaryTreeUtil::buildTree(nums);

    // ��ӡ������
    std::cout << "�����Ķ�������" << std::endl;
    BinaryTreeUtil::printTree(root);

    // �ͷ��ڴ�
    BinaryTreeUtil::deleteTree(root);

    return 0;
}