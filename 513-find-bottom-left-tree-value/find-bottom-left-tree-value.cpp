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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int ans = root->val;
        while (!qu.empty()) {
            int s = qu.size();
            for (int i = 0; i < s; i++) {
                TreeNode* temp = qu.front();
                qu.pop();
                if (i == 0) {
                    ans = temp->val;
                }
                if (temp->left != nullptr) {
                    qu.push(temp->left);
                }
                if (temp->right != nullptr) {
                    qu.push(temp->right);
                }
            }
        }
        return ans;
    }
};



