class Solution {
public:
	vector<int> result;
	vector<int> preorderTraversal(TreeNode* root) {
		if (!root) return result;
		result.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
		return result;
	}
};