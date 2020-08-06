https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
int search_index(vector < int > &inorder , int x , int start , int end)
{
    for(int i = start ;i <= end; i ++)
    {
        if(inorder[i] == x)
            return i;
    }
    return -1;
}

TreeNode * build(vector < int > &inorder , vector < int > &postorder, int l1 , int r1 , int r2)
{
    if(l1 > r1)
        return NULL;
    
    TreeNode * temp = new TreeNode(postorder[r2]);
    int index = search_index(inorder , postorder[r2] , l1 , r1);
    temp->left = build(inorder , postorder , l1 , index - 1, r2 - (r1 - index) - 1);
    temp->right = build(inorder , postorder , index + 1 , r1 , r2 - 1);
    
    return temp;
    
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        
        return build(inorder , postorder , 0 , size - 1 , size - 1);
    }
};
