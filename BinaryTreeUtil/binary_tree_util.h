// binary_tree_util.h
#ifndef BINARY_TREE_UTIL_H
#define BINARY_TREE_UTIL_H

#include <iostream>
#include <vector>
#include <queue>

class BinaryTreeUtil {
public:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};

	// �������鹹��������
	static TreeNode* buildTree(const std::vector<int>& nums) {
		if (nums.empty() || nums[0] == -1) return nullptr; // ��������Ч����

		TreeNode* root = new TreeNode(nums[0]);
		std::queue<TreeNode*> q;
		q.push(root);

		int i = 1;
		while (!q.empty() && i < nums.size()) {
			TreeNode* curr = q.front();
			q.pop();

			// ���ӽڵ�
			if (i < nums.size() && nums[i] != -1) {
				curr->left = new TreeNode(nums[i]);
				q.push(curr->left);
			}
			i++;

			// ���ӽڵ�
			if (i < nums.size() && nums[i] != -1) {
				curr->right = new TreeNode(nums[i]);
				q.push(curr->right);
			}
			i++;
		}

		return root;
	}

	// ��ӡ�����������νṹ��
	static void printTree(TreeNode* root) {
		if (!root) {
			std::cout << "����" << std::endl;
			return;
		}

		// ʹ�õݹ��ӡ���νṹ
		printTreeHelper(root, 0, std::vector<bool>());
	}

	// �����������ݹ��ӡ���νṹ
	static void printTreeHelper(TreeNode* root, int depth, std::vector<bool> flag) {
		if (!root) return;

		// ��ӡ��ǰ�ڵ�
		for (int i = 0; i < depth; i++) {
			if (i == depth - 1) {
				std::cout << (flag[depth - 1] ? "������ " : "������ ");
			}
			else {
				std::cout << (flag[i] ? "��   " : "    ");
			}
		}
		std::cout << root->val << std::endl;

		// �ݹ��ӡ������
		if (root->right) {
			flag.push_back(true);
			printTreeHelper(root->right, depth + 1, flag);
			flag.pop_back();
		}

		// �ݹ��ӡ������
		if (root->left) {
			flag.push_back(false);
			printTreeHelper(root->left, depth + 1, flag);
			flag.pop_back();
		}
	}


	// �ͷŶ������ڴ棨��ֹ�ڴ�й©��
	static void deleteTree(TreeNode* root) {
		if (!root) return;
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
};

#endif // BINARY_TREE_UTIL_H
using TreeNode = BinaryTreeUtil::TreeNode;