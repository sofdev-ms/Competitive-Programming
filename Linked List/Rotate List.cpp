https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        
        int length = 0;
        ListNode * temp = head;
        ListNode * end = NULL;
        while(temp)
        {
            length++;
            if(temp->next == NULL)
                end = temp;
            temp = temp->next;
        }
        k %= length;
        k = length - k - 1;
        temp = head;
        while(k--)
        {
            temp = temp->next;
        }
        end->next = head;
        head = temp->next;
        temp->next = NULL;
        
        return head;
        
        
    }
};
