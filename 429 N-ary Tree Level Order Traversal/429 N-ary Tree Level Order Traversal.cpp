#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	class Node {
	public:
		int val;
		vector<Node*> children;

		Node() {}

		Node(int _val) {
			val = _val;
		}

		Node(int _val, vector<Node*> _children) {
			val = _val;
			children = _children;
		}
	};

	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> tmp;
			int size = q.size();
			while (--size >= 0) {
				Node* front = q.front();
				q.pop();
				tmp.push_back(front->val);
				for (auto& n : front->children) {
					q.push(n);
				}
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