#include<queue>
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
    if (!root) return;
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()) {
        node* cur = q.front();
        q.pop();
        
        cout << to_string(cur->data) << " ";
        
        if(cur->left) {
            q.push(cur->left);
        }
        if(cur->right) {
            q.push(cur->right);
        }
    }
}