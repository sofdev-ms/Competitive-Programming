https://leetcode.com/problems/validate-binary-search-tree/

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
bool validate(TreeNode * root , TreeNode * l , TreeNode * r)
{
    if(!root)
        return true;
    if(l && root->val <= l->val || r && root->val >= r->val)
        return false;
    return validate(root->left,l,root) && validate(root->right,root,r);
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL , NULL);
    }
};
