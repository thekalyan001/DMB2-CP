https://www.youtube.com/watch?v=XLdpy0_6MR4

https://practice.geeksforgeeks.org/problems/burning-tree/1?track=amazon-trees

Given a binary tree and a node called target. Find the minimum time required to burn the complete 
binary tree if the target is set on fire. It is known that in 1 second all nodes connected to 
a given node get burned. That is its left child, right child, and parent.



Node* createParentMapping(Node* root, int target, map<Node*, Node*>&nodeToParent){
        Node* res=NULL;
        queue<Node*>q;
        q.push(root);
        nodeToParent[root]=NULL;
        
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            
            if(temp->data==target)
            res=temp;
            
            if(temp->left){
                nodeToParent[temp->left]=temp; 
                q.push(temp->left); 
            }
            
            if(temp->right){
                nodeToParent[temp->right]=temp;  
                q.push(temp->right);
            }
        }
        return res;
    }
    int burnTree(Node* root, map<Node*, Node*>&nodeToParent){
        map<Node*, bool>visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=true;
        int time=0;
        
        while(!q.empty()){
            bool flag=0;
            int size=q.size();
            
            for(int i=0;i<size;i++){
                Node* temp=q.front();q.pop();
                visited[temp]=true;
                
                //left
                if(temp->left && !visited[temp->left]){
                    flag=1;
                    q.push(temp->left);
                    visited[temp->left]=1;
                }
                //right
                if(temp->right && !visited[temp->right]){
                    flag=1;
                    q.push(temp->right);
                    visited[temp->right]=1;
                }
                //parent node
                if(nodeToParent[temp] && !visited[nodeToParent[temp]]){
                    flag=1;
                    q.push(nodeToParent[temp]);
                    visited[nodeToParent[temp]]=1;
                }
               
            }
            if(flag==1)
            time++;
        }
        return time;
    }
    int minTime(Node* root, int target) 
    {
        //create mapping
        //call burn tree
        //return
        map<Node*, Node*>nodeToParent;
        Node* targetNode=createParentMapping(root, target, nodeToParent);
        int ans=0;
        ans=burnTree(targetNode, nodeToParent);
        return ans;
    }