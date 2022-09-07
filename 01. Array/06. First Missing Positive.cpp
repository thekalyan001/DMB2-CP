https://leetcode.com/problems/first-missing-positive/

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1



int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
       //number should be always between 1 to n
       for(int i=0;i<n;i++){
           if(nums[i]<=0 or nums[i]>n)
               nums[i]=n+1;
       }
        
       //
       for(int i=0;i<n;i++){
           if(abs(nums[i])<=n){
               int index=abs(nums[i])-1;
               nums[index]=-abs(nums[index]);
           }
       }
        //if any value is +ve then index+1 will be the number as index starts from 0
        for(int i=0;i<n;i++){
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }