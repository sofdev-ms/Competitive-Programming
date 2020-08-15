https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head)
            return head;
        
        ListNode * temp = head;
        ListNode * odd = NULL;
        ListNode * even = NULL;
        
        odd = head;
        even = head->next;
        ListNode * curr = even;
        while(curr && curr->next)
        {               
            odd->next = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            odd = odd->next;
        }
        odd->next = even;
               
        
        
        return head;
    }
};
