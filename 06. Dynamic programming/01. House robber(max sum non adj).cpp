https://leetcode.com/problems/house-robber/
https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

maximum sub non adjcent ele

//using dp o(n) o(n)space
int rob(vector<int>& nums) {
	int n=nums.size();
	if(n==1)return nums[0];
	int dp[n+1];
	dp[0]=nums[0];
	dp[1]=max(nums[0], nums[1]);

	for(int i=2;i<n;i++){
		int temp=nums[i]+dp[i-2];
		int p=dp[i-1];
		dp[i]=max(p, temp);
	}
	return dp[n-1];
}


//o(n) O(1) space 
int rob(vector<int>& nums) {
// [rob1, rob2, n, n+1, .......]
	int rob1=0,rob2=0;
	for(int i:nums)
	{
		int temp=max(rob1+i,rob2);
		rob1=rob2;
		rob2=temp;  
	}
	return rob2;
}


