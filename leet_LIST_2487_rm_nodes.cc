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
    ListNode* removeNodes(ListNode* head)
    {
        vector<ListNode *(*)(ListNode *)> solutions {
            Popping_monostack,
            Reverse_and_reverse_back,
        };
        return solutions[0](head);
    }

    static ListNode* Reverse_and_reverse_back(ListNode* head)
    {
        std::function<ListNode *(ListNode *)> reverse_linked_list;
        reverse_linked_list = [&](ListNode* head)
        {
            assert(head);
            ListNode *pprev, *curr, *pnext;
            pprev = pnext = nullptr;
            curr = head;
            while (curr)
            {
                pnext = curr->next; // save .next to a pointer
                curr->next = pprev; // assign .next to the prev pointer
                pprev = curr; // forward prev pointer
                curr = pnext; // forward curr
            }
            return pprev;
        };
        ListNode * new_list = reverse_linked_list(head);
        ListNode * ptr = new_list;
        while (ptr && ptr->next)
        {
            if (ptr->val > ptr->next->val)
                ptr->next = ptr->next->next;
            else
                ptr = ptr->next;
        }
        return reverse_linked_list( new_list );
    }

    static ListNode* Popping_monostack(ListNode* head)
    {
        ListNode * dummy = new ListNode(2147483647);
        ListNode * ptr = head;
        deque<ListNode *> D { dummy };
        while (ptr)
        {
            while (D.back()->val < ptr->val)
                D.pop_back();
            D.back()->next = ptr;
            D.push_back(ptr);
            ptr = ptr->next;
        }
        return dummy->next;
    }
};
