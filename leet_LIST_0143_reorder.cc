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
    void reorderList(ListNode* head)
    {
        vector<void(*)(ListNode *)> Solutions {
            // Extra_space,
            Reverse_linked_list,
        };
        Solutions[0](head);
    }

    static void Reverse_linked_list (ListNode *head)
    {
        if (!head || !head->next)
            return ;
        ListNode * f = head, * s = head;
        while (f && f->next)
        {
            f = f->next->next;
            s = s->next;
        }
        ListNode * end, * nxt;
        end = s;
        nxt = s->next;
        s->next = nullptr ;
        s = nxt;
        while (s)
        {
            nxt = s->next;
            s->next = end;
            end = s;
            s = nxt;
        }
        s = head;
        while (s && end && s != end && s->next != end)
        {
            nxt = s->next;
            if (!nxt)
                break ;
            ListNode * new_node = new ListNode(end->val, nxt);
            s->next = new_node;
            s = nxt;
            end = end->next;
        }
    }

    static void Extra_space (ListNode * head)
    {
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
