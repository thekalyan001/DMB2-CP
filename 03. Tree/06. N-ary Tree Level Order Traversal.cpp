https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };



vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        vector<int>temp;
        queue<Node*>q; q.push(root);
        
        while(!q.empty()){
            ans.emplace_back();
            int size=q.size();
            
            for(int i=0;i<size;i++){
                Node* temp=q.front();q.pop();
                ans.back().push_back(temp->val);
                
                for(Node *it: temp->children){
                    q.push(it);
                }
            }
        }
        return ans;
    }



using dfs

	vector<vector<int>>ans;
    dfs(Node* root, int level){
    	if(!root)return;

    	if(level==ans.size())
    		ans.emplace_back();

    	for(Node* temp:root->children){
    		dfs(temp, level+1);
    	}
    }
    vector<vector<int>> levelOrder(Node* root) {
    	if(!root)return {};
    	dfs(root, 0);
    	return ans;
    }