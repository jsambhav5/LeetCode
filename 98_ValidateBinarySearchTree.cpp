/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return validate(root, -1000000000000, 1000000000000);
	}

private:
	bool validate(TreeNode* node, long long min, long long max) {
		if (node == nullptr) return true;
		if (node->val <= min || node->val >= max) return false;
		
		bool leftIsValid = validate(node->left, min, node->val);
		bool rightIsValid = validate(node->right, node->val, max);
		
		return leftIsValid && rightIsValid;
	}
};
