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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        vector<ListNode*>   res;
        int N = 0; // how many nodes
        ListNode    *p = head;
        while (p) {++N; p=p->next;}
        int slotSize = N / k;
        int remainingSlots = N % k;
        p = head;
        int i = -1, j;
        // cout << N << slotSize << remainingSlots << endl;
        while (++i < k)
        {
            ListNode    *possibleTail = nullptr;

            res.push_back(p);
            j = -1;
            while (++j < slotSize)
            {
                if (!p)
                    continue ;
                possibleTail = p;
                p = p->next;
            }
            if (p && remainingSlots)
            {
                possibleTail = p;
                p = p->next;
                --remainingSlots;
            }
            if (possibleTail)
            {
                possibleTail->next = nullptr;
            }
        }
        return res;

    }
};

