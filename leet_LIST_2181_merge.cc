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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode    *fast, *slow;
        int     temp = 0;

        fast = head->next;
        slow = head;
        while (fast)
        {
            if (fast->val == 0)
            {
                slow = slow->next;
                slow->val = temp;
                temp = 0;
            }
            else
            {
                temp += fast->val;
            }
            fast = fast->next;
        }
        slow->next = 0;
        return head->next;
        //  Beginning of the linked list have Node.val == 0
    }
};
