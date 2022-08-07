
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        deque<ListNode>     dq;
        ListNode            *dummy; // dummy tail

        while (head)
        {
            dq.push_back(*head);
            head = head->next;
        }
        dummy = new ListNode();
        head = dummy;
        while (!dq.empty())
        {
            ListNode    curr = dq.back();
            ListNode    *temp = new ListNode(curr.val);

            head->next = temp;
            dq.pop_back();
            head = head->next;
        }
        return (dummy->next);
    }
};

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
