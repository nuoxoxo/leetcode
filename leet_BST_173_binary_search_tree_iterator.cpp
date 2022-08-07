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
class BSTIterator {

private:    

    void inorder_traversal(TreeNode* node)
    {
        if (!node)
            return ;
        inorder_traversal(node->left);
        arr.push_back(node->val);
        inorder_traversal(node->right);
    }

public:

    vector<int> arr;
    int         i = 0;

    BSTIterator(TreeNode* root)
    {
        inorder_traversal(root);
    }
    
    int next()
    {
        int n = (int) arr.size();
        if (i < n)
            return arr[i++];
        return arr[n - 1];
    }
    
    bool hasNext()
    {
        return i < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
