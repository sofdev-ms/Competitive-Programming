https://leetcode.com/problems/add-two-numbers-ii/

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
ListNode * reverse(ListNode * head)
{
    if(!head)
        return head;
    
    ListNode * temp = head;
    ListNode * curr = head->next;
    head->next = NULL;
    
    while(temp && curr)
    {
        head = curr->next;
        curr->next = temp;
        temp = curr;
        curr = head;
    }
    
    return temp;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* L1, ListNode* L2) {
        
        L1 = reverse(L1);
        L2 = reverse(L2);
        
        int carry = 0;
        ListNode * res = NULL;
        ListNode * temp = NULL;
        while(L1 || L2)
        {
            int sum = carry;
            if(L1)
            {
                sum += L1 -> val;
                L1 = L1 -> next;
            }
            if(L2)
            {  
                sum += L2 -> val;
                L2 = L2->next;
            }
            carry = sum / 10;
            sum %= 10;
            if(!res)
            {
                res = new ListNode(sum);
                temp = res;
            }
            else
            {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            
        }
        if(!res)
            return res;
        
        if(carry != 0)
        {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }
            return reverse(res);
        
        
    }
};
