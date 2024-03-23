/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullp) {}
 *     ListNode(int x) : val(x), next(nullp) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if ( ! head || ! head->next )
            return ;
        std::deque<ListNode *> dq;
        ListNode * p = head;
        int N = 0;
        while (p)
        {
            dq.push_back( p );
            p = p->next;
            ++N;
        }
        int i = -1;
        p = head;
        while (++i < N / 2)
        {
            ListNode * node = dq.back();
            dq.pop_back();
            node->next = p->next;
            p->next = node;
            p = p->next->next;
        }
        p->next = nullptr;
    }
};
