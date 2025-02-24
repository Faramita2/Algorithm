#include <iostream>
#include <vector>
#include <queue>
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

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> tmp;
			int size = q.size();
			while (--size >= 0) {
				TreeNode* front = q.front();
				q.pop();
				tmp.push_back(front->val);
				if (front->left != nullptr) q.push(front->left);
				if (front->right != nullptr) q.push(front->right);
			}
			res.push_back(tmp);
		}

		return res;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}