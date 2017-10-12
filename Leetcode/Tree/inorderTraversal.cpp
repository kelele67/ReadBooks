#include <stack>
//struct TreeNode{
//int val;
//TreeNode *left;
//TreeNode *right;
//TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack< const TreeNode* > s;
		const TreeNode *p = root;
		while (!s.empty() || p != nullptr) {
			if (p !+ nullptr) {
				s.push(p);
				p = p->left;
			} else {
				p = s.top();
				result.push_back(p->val);
				s.pop();
				p = p->right;
			}
		}
		return result;
	}
};
