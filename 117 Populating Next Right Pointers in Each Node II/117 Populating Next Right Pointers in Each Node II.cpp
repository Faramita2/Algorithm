#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
	class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node* next;

		Node() : val(0), left(NULL), right(NULL), next(NULL) {}

		Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

		Node(int _val, Node* _left, Node* _right, Node* _next)
			: val(_val), left(_left), right(_right), next(_next) {
		}
	};

	Node* connect(Node* root) {
		Node* currParent, * baseChild, * nextChild, * currChild;
		currParent = root;
		while (currParent) {
			while (currParent->next != nullptr && currParent->left == nullptr && currParent->right == nullptr) currParent = currParent->next;
			baseChild = currChild = currParent->left ? currParent->left : currParent->right;
			while (currChild) {
				if (currParent->right && currChild != currParent->right) nextChild = currParent->right;
				else {
					currParent = currParent->next;
					while (currParent && !currParent->left && !currParent->right) currParent = currParent->next;
					nextChild = currParent ? currParent->left ? currParent->left : currParent->right : currParent;
				}
				currChild->next = nextChild;
				currChild = nextChild;
			}
			currParent = baseChild;
		}

		return root;
	}

	Node* connect(Node* root) {
		if (root == nullptr)
			return root;
		Node* dummy = new Node();
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* pre = dummy;
			int size = q.size();
			while (--size >= 0) {
				auto front = q.front();
				q.pop();
				pre->next = front;
				pre = front;
				if (front->left != nullptr)
					q.push(front->left);
				if (front->right != nullptr)
					q.push(front->right);
			}
			dummy->next = nullptr;
			pre->next = nullptr;
		}
		delete dummy;
		return root;
	}
};
int main()
{
	std::cout << "Hello World!\n";
}