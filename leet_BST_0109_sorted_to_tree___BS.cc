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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int> v;
        ListNode    *p;

        p = head;
        while (p)
            v.push_back(p->val), p = p->next;
        return make_tree(v, 0, (int) v.size() - 1);
    }

    TreeNode    *make_tree(vector<int>& v, int L, int R)
    {
        TreeNode *node;
        int mid;
    
        if (L > R)
            return 0;
        mid = (R - L) / 2 + L;
        node = new TreeNode(v[mid]);
        node->left = make_tree(v, L, mid - 1);
        node->right = make_tree(v, mid + 1, R);
        return node;

    }
};

