class Solution {
private:
        ListNode*   h;
public:
    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        ListNode*   ptr;
        int pos, res;

        ptr = h;
        pos = 1;
        while (ptr)
        {
            if (!(rand() % pos))    res = ptr->val;
            ptr = ptr->next;
            ++ pos;
        }
        return res ;
    }
};
