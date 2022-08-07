class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        return dfs(head, root);
    }

    bool cmp(ListNode* head, TreeNode* root)
    {
        if (!head)
            return true;
        if (!root || root->val != head->val)
            return false;
        return cmp(head->next, root->left) || cmp(head->next, root->right);
    }

    bool dfs(ListNode *head, TreeNode* root)
    {
        if (!root)
            return false;
        if (cmp(head, root))
            return true;
        return dfs(head, root->left) || dfs(head, root->right);
    }
};
