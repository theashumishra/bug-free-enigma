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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
    
private:
    // Returns a pair: {lca, depth} for the current subtree.
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) return {nullptr, 0};
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        // If left subtree is deeper, propagate left's LCA.
        if (left.second > right.second)
            return {left.first, left.second + 1};
        // If right subtree is deeper, propagate right's LCA.
        else if (right.second > left.second)
            return {right.first, right.second + 1};
        // If both depths are equal, current node is the LCA.
        else
            return {node, left.second + 1};
    }
};
