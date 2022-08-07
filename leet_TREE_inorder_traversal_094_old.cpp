class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> vect;
        TreeNode*   p;
        
        p = root;
        traverse(vect, p);
        
        return (vect);
    }

    void    traverse(vector<int>& arr, TreeNode* p)
    {
        if (!p) return ;
        traverse(arr, p->left);
        arr.push_back(p->val);
        traverse(arr, p->right);
    }
};
