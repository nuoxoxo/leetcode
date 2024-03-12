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
    ListNode* removeZeroSumSublists(ListNode* head) {
        assert(head);
        if (!head->next) {
            if (head->val == 0)
                return nullptr;
            return head;
        }
        ListNode * dummy = new ListNode(-1, head);
        
        map<int, ListNode*> D;
        D[0] = dummy;
        int prefix = 0;
        ListNode * node = dummy;
        while (node) {
            prefix += node->val;
            D[prefix] = node;
            node = node->next;
        }
        prefix = 0;
        node = dummy;
        while (node) {
            prefix += node->val;
            // in D such prefix must exsits and might be updated previously
            node->next = D[ prefix ]->next;
            node = node->next;
        }
        return dummy->next;
        // D[prefix] = node;
        /*
        while (node->next) {
            prefix += node->val;
            if (!prefix) {
                head = node->next;
                D.clear();
            }
            else {
                if (D.find(prefix) != D.end())
                {
                    ListNode * prev = D[prefix];
                    int temp = prefix + prev->next->val;
                    while (temp ^ prefix) {
                        ListNode * p = D[temp];
                        if (p && p->next) {
                            temp += p->next->val;
                        }
                        D.erase(temp);
                    }
                    prev->next = node->next;
                }
                else
                {
                    D[prefix] = node;
                }
            }
            */

            // node = node->next;
            /*
            if (D.find(prefix) != D.end()) {
                cout << "wow - " << node->val << endl;
                D[prefix]->next = node->next->next;
                D[prefix] = node->next;
                node = node->next;
                if (!node || !node->next) {
                    if (!dummy->next || dummy->next->val == 0)
                        return node;
                    return dummy->next;
                }
            } else {
                D[prefix] = node->next;
                node = node->next;
            }
            */
        

        // return head;
    }
};
