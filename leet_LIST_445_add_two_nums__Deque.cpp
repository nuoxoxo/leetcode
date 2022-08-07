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
    ListNode* addTwoNumbers(ListNode* a, ListNode* b)
    {
        deque<int>  s1, s2;
        ListNode*   head ;
        int         carry;

        while (a)
        {
            s1.push_front(a->val);
            a = a->next;
        }
        while (b)
        {
            s2.push_front(b->val);
            b = b->next;
        }
        head = NULL;
        carry = 0;
        while (carry || !s1.empty() || !s2.empty())
        {
            ListNode*   node = new ListNode(0);
            int         n1, n2, temp;
            

            if (!s1.empty())
            {
                n1 = s1.front();
                s1.pop_front();
            }
            else
                n1 = 0;
            if (!s2.empty())
            {
                n2 = s2.front();
                s2.pop_front();
            }
            else
                n2 = 0;
            temp = n1 + n2 + carry;
            node->val = temp % 10;
            node->next = head;
            head = node;
            carry = temp / 10;
        }
        return head ;
    }
};
