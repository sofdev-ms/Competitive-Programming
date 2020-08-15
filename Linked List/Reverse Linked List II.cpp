https://leetcode.com/problems/reverse-linked-list-ii/

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
ListNode * reverse(ListNode * root , int size)
{
    
    ListNode * prev = root;
    ListNode * curr = root->next;
    
    root->next = NULL;
    size--;
    while(size --)
    {
        ListNode * Next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    root->next = curr;
    return prev;
}
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 1 ;
        ListNode * temp = head;
        while( i < m - 1)
        {
            temp = temp->next;
            i++;
        }
        if(m!=1)
        temp->next = reverse(temp->next , n - m + 1);
        else
            head = reverse(temp , n - m + 1);
        
        return head;
        
    }
};
