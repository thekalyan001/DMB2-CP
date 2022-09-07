https://leetcode.com/problems/3sum-closest/

int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)return 0;
        int closest=nums[0]+nums[1]+nums[2]; //first 3 sum
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue; //duplicate
            
            int j=i+1, k=n-1;
            while(j<k){
                int currSum=nums[i]+nums[j]+nums[k];
                if(currSum==target)return currSum; //found target then itself
                if(abs(target-currSum)<abs(target-closest)) //minimum sum is  
                    closest=currSum;
                
                if(currSum<target)
                    j++;
                else
                    k--;
            }
        }
        return closest;
    }