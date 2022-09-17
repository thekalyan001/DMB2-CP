https://www.codingninjas.com/codestudio/problems/ancestors_920386?leftPanelTab=0

time-O(n) space O(n)stack worst size skwed tree else hight of tree logn

idea is to check which side will give the correct sooution then goto that side

bool printAnc(TreeNode<int> *root, int k, vector<int>&v){
    
    if(root==NULL)
        return false;
    
    if(root->data==k)
        return true;
    
    
    bool left=printAnc(root->left, k, v);
    bool right=printAnc(root->right, k, v);
    if(left==true or right==true)
    {
        v.push_back(root->data);
        return true;
    }
    return false;
}
vector<int> ancestorsInBinaryTree(TreeNode<int> *root,int k){
    TreeNode<int>*p=root;
    vector<int>v;
    printAnc(root, k, v);
    if(v.size()==0)return {-1};
    
    return v;
}
