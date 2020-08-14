https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * temp = head;
        head = NULL;
        ListNode * prev = NULL;
        while(temp)
        {
            int count = 0;
            
            // check if duplicate nodes
            while(temp && temp->next && temp->val == temp->next->val)
            {
                count++;
                temp = temp->next;
            }
            
            // not a duplicate
            if(count==0)
            {
                if(!head)
                    head = temp;
                
                if(prev)
                    prev->next = temp;
                
                prev = temp;
                
            }
            
            temp = temp->next;
           
        }
        if(prev)
        prev->next = NULL;
        return head;
    }
};
