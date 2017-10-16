//想法是对二叉树进行前序遍历
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreeToSequence {
public:
    string toSequence(TreeNode* root) {
        string str = "";
    	if (root == nullptr) {
    		return "";
    	} else {
    		str += "(";
    		str += toSequence(root->left);
    		str += toSequence(root->right);
    		str += ")";
    		return str;
    	}
    }
};