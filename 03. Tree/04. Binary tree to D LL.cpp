https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1


void inorder(Node* root, vector<int>&v){
        if(!root)return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    Node * bToDLL(Node *root)
    {
        if(!root)return NULL;
        
        vector<int>v;
        inorder(root, v);
        
        Node *head=new Node();
        head->data=v[0];
        head->left=head->right=NULL;
        
        Node* node=head;
        for(int i=1;i<v.size();i++){
            Node* temp=new Node();
            temp->data=v[i];
            temp->left=node;
            temp->right=NULL;
            
            node->right=temp;
            node=node->right;
        }
        return head;
    }