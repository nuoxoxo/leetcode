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
    int numComponents(ListNode* head, vector<int>& nums)
    {
        set<int> S(begin(nums), end(nums));
        int cut = 1;
        int res = 0;
        while (head)
        {
            if (S.find(head->val) != end(S))
            {
                if (cut)
                    res++;
                cut = 0;
            }
            else
            {
                cut = 1;
            }
            head = head->next;
        }
        return res;
    }
};
