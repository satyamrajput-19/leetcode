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
    long long prev = LLONG_MIN;
    bool result = true;

    void inOrder(TreeNode* root) {
        if (root == nullptr) return;

        inOrder(root->left);

        if (prev >= root->val) {
            result = false;
        }

        prev = root->val;

        inOrder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        prev = LLONG_MIN;
        result = true;
        inOrder(root);
        return result;
    }
};
