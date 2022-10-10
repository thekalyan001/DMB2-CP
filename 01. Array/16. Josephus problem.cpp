https://practice.geeksforgeeks.org/problems/josephus-problem/1

	int ans=0;
    void josh(vector<int>v, int k, int ind){
        if(v.size()==1){
            ans=v[0];return;
        }
        ind=(ind+k)%v.size();
        v.erase(v.begin()+ind);
        josh(v, k, ind);
    }
    int josephus(int n, int k)
    {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int ind=0;k--; // k-1 th person will be killed
        josh(v,k,ind);
        return ans;
    }