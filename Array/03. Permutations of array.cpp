https://leetcode.com/problems/permutations/
vector<vector<int>>ans;
    void permu(vector<int>&nums,int count){
        if(count>=nums.size())
        { ans.push_back(nums);return;}
        
        for(int i=count;i<nums.size();i++)
        {
            swap(nums[count],nums[i]);
            permu(nums,count+1);
            swap(nums[count],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         permu(nums,0);
        return ans;
    }