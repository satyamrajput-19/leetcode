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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int s = qu.size();

            for (int i = 1; i <= s; i++) {
                TreeNode* temp = qu.front();
                qu.pop();
                if (temp->left)
                    qu.push(temp->left);
                if (temp->right)
                    qu.push(temp->right);
                if (i == s) {
                    result.push_back(temp->val);
                }
            }
        }

        return result;
    }
};
