#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};

	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		if (root == nullptr) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			double sum = 0;
			int size = q.size();
			int d = size;
			while (--size >= 0) {
				TreeNode* front = q.front();
				sum += front->val;
				q.pop();
				if (front->left != nullptr) q.push(front->left);
				if (front->right != nullptr) q.push(front->right);
			}

			res.push_back(sum / d);
		}

		return res;
	}
};

int main()
{
	auto node1 = new Solution::TreeNode(3);
	auto node2 = new Solution::TreeNode(9);
	auto node3 = new Solution::TreeNode(20);
	auto node4 = new Solution::TreeNode(15);
	auto node5 = new Solution::TreeNode(7);

	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node3->right = node5;

	Solution s;
	auto res = s.averageOfLevels(node1);

	for (double d : res) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}