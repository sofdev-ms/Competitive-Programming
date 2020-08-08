https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector < vector < int > > ans;
        if(!root)
            return ans;
        int level = 0;
        queue < pair < TreeNode * , int > > s;
        s.push({root , 0});
        
        while(!s.empty())
        {
            pair < TreeNode *, int > p = s.front();
            s.pop();
            if(p.second == level)
            {
                ans.push_back(vector < int > ());
                level++;
            }
            ans[p.second].push_back(p.first->val);
            
            if(p.first -> left)
                s.push({p.first->left , p.second + 1});
            if(p.first->right)
                s.push({p.first->right , p.second + 1});
            
        }
        for(int i = 1; i < level; i += 2)
            reverse(ans[i].begin() , ans[i].end());
        return ans;
    }
};
