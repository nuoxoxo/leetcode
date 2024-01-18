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
    void reorderList(ListNode* head) {
        if ( ! head || ! head->next || ! head->next->next)
            return ;
        std::deque< ListNode * > dq;
        ListNode * ptr = head;
        int len = 0;
        while (ptr) {
            dq.push_back( ptr );
            ptr = ptr->next;
            len++;
        }
        int i = -1;
        ptr = head;
        while (++i < len / 2) {
            ListNode * node = dq.back();
            node->next = ptr->next;
            ptr->next = node;
            ptr = ptr->next->next;
            dq.pop_back();
        }
        ptr->next = nullptr;
    }
};
