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
        ListNode * L = head;
        assert (head->next != nullptr);
        ListNode * R = head->next;
        int running = 0;
        while (R != nullptr)
        {
            if (R->val == 0)
            {
                L = L->next;
                L->val = running;
                running = 0;
            }
            else
            {
                running += R->val;
            }
            R = R->next;
        }
        L->next = nullptr;
        return head->next;
    }
};
