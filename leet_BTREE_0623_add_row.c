/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* DFS(struct TreeNode *, int, int);

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {

    return (struct TreeNode *) DFS(root, val, depth);
}

struct TreeNode* DFS(struct TreeNode* root, int val, int depth) {

    if (!root)
        return NULL;

    if (depth == 1)
    {
        struct TreeNode* node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        if (!node)
            return NULL ;

        node->val = val;
        node->left = root;
        node->right = NULL;
        return node;
    }
    if (depth == 2)
    {
        struct TreeNode * L = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        struct TreeNode * R = (struct TreeNode *) malloc(sizeof(struct TreeNode));

        if (!L || !R)
            return NULL;
        L->val = val;
        R->val = val;

        L->left = root->left;
        L->right = NULL;
        R->left = NULL;
        R->right = root->right;

        root->left = L;
        root->right = R;
        return root;
    }

    root->left = DFS(root->left, val, depth - 1);
    root->right = DFS(root->right, val, depth - 1);
    return root;
}
