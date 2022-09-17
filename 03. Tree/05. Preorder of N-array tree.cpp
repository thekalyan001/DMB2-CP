 https://leetcode.com/problems/n-ary-tree-preorder-traversal/

//recursive
 void nPre(Node* root, vector<int>&ans){
    if(!root)return;
    ans.push_back(root->val);
    for(auto &child:root->children){
        nPre(child, ans);
    }
}
vector<int> preorder(Node* root) {
    vector<int>ans;
    if(!root)return ans;
    nPre(root, ans);
    return ans;
}


--------------------------------------------------
//iterative

vector<int> preorder(Node* root) {
    vector<int>ans;
    stack<Node*>st;
    st.push(root);

    while(!st.empty()){
        Node* curr=st.top();st.pop();
        ans.push_back(curr->val);
        for(int i=curr->children.size()-1;i>=0;i--){
            if(curr->children[i])
                st.push(curr->children[i]);
        }

    }
    return ans;
}