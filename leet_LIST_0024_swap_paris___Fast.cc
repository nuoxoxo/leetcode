/* ************************************ nuo *** */

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !(head->next))
            return head ;

        ListNode*   temp = new ListNode() ;
        ListNode    *prev, *curr;
        
        temp->next = head;
        prev = temp;
        curr = head ;
        while (curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            prev = curr ;
            curr = curr->next;
        }
        return temp->next ;
    }
};
