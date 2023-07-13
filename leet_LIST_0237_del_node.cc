/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node)
    {
        //  You will not be given access to the head node
        //  and it is guaranteed the given node is not the tail node

        node->val = node->next->val;
        node->next = node->next->next;
    }
};
