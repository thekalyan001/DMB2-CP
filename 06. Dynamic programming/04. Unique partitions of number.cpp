https://practice.geeksforgeeks.org/problems/unique-partitions1041/1

void solve(int i, int n, int sum, vector<int>&v, vector<int>temp, vector<vector<int>>&ans){
	    if(sum>n) return;
	    if(i>=n){
	        if(sum==n)ans.push_back(temp); return;
	    }
	    
	    temp.push_back(v[i]); //take current val
	    solve(i, n, sum+v[i], v, temp, ans); //include then take the sum too
	    temp.pop_back();
	    solve(i+1, n, sum, v, temp, ans); //didn't include then dont take into sum
	}
    vector<vector<int>> UniquePartitions(int n) {
        vector<int>v, temp;
        for(int i=n;i>=1;i--)v.push_back(i);
        vector<vector<int>>ans;
        solve(0, n, 0, v, temp, ans); //i, n, sum, temp, ans
        return ans;
    }
