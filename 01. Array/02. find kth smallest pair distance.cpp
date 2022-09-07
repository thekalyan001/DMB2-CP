https://leetcode.com/problems/find-k-th-smallest-pair-distance/

int findPairs_inRange(vector<int>&nums, int mid){
        int index=0, totalPairDist_count=0;
        for(int i=0;i<nums.size();i++){
            while(index<nums.size() && nums[index]-nums[i]<=mid) //nums[index]-nums[i] pair difference
                index++; //if it is in range then check till what index
            
            totalPairDist_count+=index-i-1;
        }
        return totalPairDist_count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int mn=0, mx=1000000;
        sort(nums.begin(), nums.end());
        vector<int>ans;
        while(mn<mx){
            int mid=(mn+mx)/2;
            if(findPairs_inRange(nums, mid)>=k) //if the pair in range coming greater then it does not lie in range
                mx=mid;
            else
                mn=mid+1;
        }
        return mn;
    }