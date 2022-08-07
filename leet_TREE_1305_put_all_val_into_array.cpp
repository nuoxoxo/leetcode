class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> E;
        fill(E, root1);
        fill(E, root2);
        sort(E.begin(), E.end());

        return E ;
    }
    
    void    fill(vector<int>& E, TreeNode* R)
    {
        if (!R) return ;
        fill(E, R->right);
        fill(E, R->left);
        E.push_back(R->val); // can be placed at any level after if
    }
};
