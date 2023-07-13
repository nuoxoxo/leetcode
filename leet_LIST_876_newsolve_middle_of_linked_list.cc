
class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode    *half, *fast;
        half = fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            half = half->next;
        }
        return half;
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
