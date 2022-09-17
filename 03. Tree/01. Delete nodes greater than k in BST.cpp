https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1

Node* deleteNode(Node* root, int k)
    {
    //   if(!root)return root;
    //   if(root->data==k)return root->left; //right side will also be greater
    //   else if(root->data>k)
    //      return deleteNode(root->left, k);
       
    //   root->right=deleteNode(root->right, k);
    //   return root;
       
       
       
       if(root==NULL) return NULL;
       if(root->data>=k) 
         root=deleteNode(root->left,k);
       else root->right=deleteNode(root->right,k);
       return root;
}