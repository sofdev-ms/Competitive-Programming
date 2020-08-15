https://leetcode.com/problems/linked-list-components/

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
    int numComponents(ListNode* head, vector<int>& G) {
        int count[10001] = {0};
        int size = G.size();
        for(int i = 0; i < size;  i ++)
        {
            count[G[i]] = 1;
        }
        int ans = 0;
        bool check = false;
        while(head)
        {
            if(count[head->val])
                check = true;
            else if(check)
                ans++ , check = false;
            head = head -> next;
        }
        if(check)
            ans++;
        return ans;
    }
};

