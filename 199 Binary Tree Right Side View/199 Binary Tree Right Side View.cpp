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

	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			int right;
			while (--size >= 0) {
				TreeNode* front = q.front();
				right = front->val;
				q.pop();
				if (front->left != nullptr) q.push(front->left);
				if (front->right != nullptr) q.push(front->right);
			}

			res.push_back(right);
		}

		return res;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}