https://leetcode.com/problems/permutations-ii/
set<vector<int>>ans;
    void permuteP(vector<int>&nums, int count){
        if(count>=nums.size()){
            ans.insert(nums);return;
        }
        for(int i=count;i<nums.size();i++){
            swap(nums[count], nums[i]);
            permuteP(nums, count+1);
            swap(nums[count], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permuteP(nums, 0);
        vector<vector<int>>sol;
        for(auto i:ans){
            sol.push_back(i);
        }
        return sol;
    }