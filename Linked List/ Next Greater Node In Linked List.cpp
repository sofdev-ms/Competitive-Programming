https://leetcode.com/problems/next-greater-node-in-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
            
        vector < int > ans;
        if(!head)
            return ans;
        
        stack < pair < int,int > > s;
        int i = 0;
        while(head)
        {
            ans.push_back(0);
            while(!s.empty() && s.top().first < head->val)
            {
                ans[s.top().second] = head->val;
                s.pop();
            }
            s.push({head->val , i++});
            head = head->next;
        }
        return ans;
    }
};
