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
    bool isPalindrome(ListNode* head)
    {
        ListNode        *fst, *slw;
        vector<int>     arr;
        int             i;

        if (!head || !(head->next))
            return true;
        slw = head;
        fst = head;
        while (fst && fst->next)
        {
            arr.push_back(slw->val);
            fst = fst->next->next;
            slw = slw->next;
        }
        if (fst != nullptr)
            slw = slw->next;
        //cout << arr.size() << endl;
        i = arr.size() - 1;
        while (slw)
        {
            if (slw->val != arr[i])
                return false;
            slw = slw->next;
            i--;
        }
        return true;
            
    }
};
