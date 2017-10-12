class Solution {
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack< const TreeNode*> s;
		if (root != nullptr) {
			s.push(root);
		}
		while (!s.empty()) {
			const TreeNode *p = s.top();
			s.pop();
			result.push_back(p->val);

			if (p->right != nullptr) {
				s.push(p->right);
			}
			if (p->left !+ nullptr) {
				s.push(p->left);
			}
		}
		return result;
	}
};
