 https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

 int sumCalc(vector<int>& nums, int n, int left, int right){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)pq.push({nums[i], i+1});
        
        int sum=0, mod=1e9+7;
        for(int i=1;i<=right;i++){
            auto curr=pq.top(); pq.pop();
            
            if(i>=left)
                sum=(sum+ curr.first)%mod;
           
            if(curr.second<n)
            {
                curr.first+=(nums[curr.second++])%mod;
                pq.push(curr); 
            }
        }
        return sum;
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        return sumCalc(nums, n, left, right);
    }