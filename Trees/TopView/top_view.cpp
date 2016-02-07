/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * root)
{
    if (!root) return;
    node* cur = root->left;
    stack<node*> st;
    while (cur) {
        st.push(cur);
        cur = cur->left;
    }
    
    while(!st.empty()) {
        cout << to_string(st.top()->data) << " ";
        st.pop();
    }
    cout << to_string(root->data) << " ";

    cur = root->right;
    while(cur) {
        cout << to_string(cur->data) << " ";
        cur = cur->right;
    }
}
