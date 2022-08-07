class Solution {
public:
    bool findTarget(TreeNode* root, int k)
    {
        vector<int> arr;

        get_vals(root, arr);
        int i = 0;
        int j = (int) arr.size() - 1;
        while (i < j)
        {
            int S = arr[i] + arr[j];
            if (k > S)          i ++;
            else if (k < S)     j --;
            else if (k == S)    return true ;
        }
        return false ;
    }
    
    void    get_vals(TreeNode *node, vector<int>& arr)
    {
        if (!node)   return ;
        get_vals(node->left, arr);
        arr.push_back(node->val);
        get_vals(node->right, arr);
    }
};
