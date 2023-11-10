// 94. Binary Tree Inorder Traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<tuple<TreeNode *, bool>> s;
        if (root) {
            s.push(make_tuple(root, false));
        }
        while (!s.empty()) {
            TreeNode *n;
            bool toPush;
            tie(n, toPush) = s.top();
            s.pop();
            if (toPush) {
                v.push_back(n->val);
            } else {
                if (n->right) {
                    s.push(make_tuple(n->right, false));
                }
                s.push(make_tuple(n, true));
                if (n->left) {
                    s.push(make_tuple(n->left, false));
                }
            }
        }
        return v;
    }
};
