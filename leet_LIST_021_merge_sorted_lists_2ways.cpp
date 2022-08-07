//  dummy node using constructor

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode *head = new ListNode();
        ListNode *tail;

        if (!list1)
            return (list2);
        if (!list2)
            return (list1);
        tail = head;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return (head->next);
    }
};

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

/*

// recursive, faster

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (!list1) return (list2);
        if (!list2) return (list1);
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return (list1);
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return (list2);
    }
};

*/
