https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
            return NULL;
        if(root->val > key)
            root->left = deleteNode(root->left , key);
        else if(root->val < key)
            root->right = deleteNode(root->right , key);
        else
        {
            if(!root->left)
            {
                TreeNode * right = root->right;
                delete root;
                return right;
            }
            else if(!root->right)
            {
                TreeNode * left = root->left;
                delete root;
                return left;
            }
            else
            {
                TreeNode *node = root;
                root = root->left;
                while(root->right)
                    root = root->right;
                
                node->val = root->val;
                
                node->left = deleteNode(node->left , root->val);                
                
                return node;
                
            }
        }
        
        
        return root;
        
    }
};
