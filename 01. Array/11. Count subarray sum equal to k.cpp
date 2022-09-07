https://leetcode.com/problems/subarray-sum-equals-k/

  int subarraySum(vector<int>& nums, int k) {
        int res=0,sum=;
        unordered_map<int, int>prevSum;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(sum==k)
                res++;
            
            res+=prevSum[sum-k];
            
            prevSum[sum]++;
        }
        return res;
    }