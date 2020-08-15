https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode * temp = head;
        ListNode * prev = NULL;
        while(temp && temp->next)
        {
            if(prev == NULL)
            head = temp->next;
            else
                prev->next = temp->next;
            ListNode * curr = temp->next->next;
            
            temp->next->next = temp;
            temp->next = curr;
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
