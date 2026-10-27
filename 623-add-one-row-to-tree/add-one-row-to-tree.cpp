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
 */class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, int depth, int curr_depth) {
        if (root == nullptr) return nullptr;
        if (curr_depth == depth - 1) {
            TreeNode* lst = root->left;
            TreeNode* rst = root->right;
            root->left = new TreeNode(val, lst, nullptr);
            root->right = new TreeNode(val, nullptr, rst);
            return root; 
        }
        root->left = solve(root->left, val, depth, curr_depth + 1);
        root->right = solve(root->right, val, depth, curr_depth + 1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        return solve(root, val, depth, 1);
    }
};