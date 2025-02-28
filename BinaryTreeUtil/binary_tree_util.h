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

	// 根据数组构建二叉树
	static TreeNode* buildTree(const std::vector<int>& nums) {
		if (nums.empty() || nums[0] == -1) return nullptr; // 空树或无效输入

		TreeNode* root = new TreeNode(nums[0]);
		std::queue<TreeNode*> q;
		q.push(root);

		int i = 1;
		while (!q.empty() && i < nums.size()) {
			TreeNode* curr = q.front();
			q.pop();

			// 左子节点
			if (i < nums.size() && nums[i] != -1) {
				curr->left = new TreeNode(nums[i]);
				q.push(curr->left);
			}
			i++;

			// 右子节点
			if (i < nums.size() && nums[i] != -1) {
				curr->right = new TreeNode(nums[i]);
				q.push(curr->right);
			}
			i++;
		}

		return root;
	}

	// 打印二叉树（树形结构）
	static void printTree(TreeNode* root) {
		if (!root) {
			std::cout << "空树" << std::endl;
			return;
		}

		// 使用递归打印树形结构
		printTreeHelper(root, 0, std::vector<bool>());
	}

	// 辅助函数：递归打印树形结构
	static void printTreeHelper(TreeNode* root, int depth, std::vector<bool> flag) {
		if (!root) return;

		// 打印当前节点
		for (int i = 0; i < depth; i++) {
			if (i == depth - 1) {
				std::cout << (flag[depth - 1] ? "├── " : "└── ");
			}
			else {
				std::cout << (flag[i] ? "│   " : "    ");
			}
		}
		std::cout << root->val << std::endl;

		// 递归打印右子树
		if (root->right) {
			flag.push_back(true);
			printTreeHelper(root->right, depth + 1, flag);
			flag.pop_back();
		}

		// 递归打印左子树
		if (root->left) {
			flag.push_back(false);
			printTreeHelper(root->left, depth + 1, flag);
			flag.pop_back();
		}
	}


	// 释放二叉树内存（防止内存泄漏）
	static void deleteTree(TreeNode* root) {
		if (!root) return;
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
};

#endif // BINARY_TREE_UTIL_H
using TreeNode = BinaryTreeUtil::TreeNode;