/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * lca(node * root, int v1,int v2)
{
    if (root == NULL) return NULL;
    int data = root->data;
    if (min(v1, v2) > data) {
        return lca(root->right, v1, v2);
    } else if (max(v2, v1) < data) {
        return lca(root->left, v1, v2);
    } else {
        return root;
    }
}