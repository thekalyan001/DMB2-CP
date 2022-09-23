https://leetcode.com/problems/count-array-pairs-divisible-by-k/discuss/1802744/2183.-Count-Array-Pairs-Divisible-by-K


https://leetcode.com/problems/count-array-pairs-divisible-by-k/


long long countPairs(vector<int>& nums, int k) {
	unordered_map<int,int>mp;
	long long ans=0;
	int n=nums.size();

	for(int i=0;i<n;i++){
		int gcd=__gcd(nums[i], k);
		int need_num=k/gcd;

		for(auto& [a, b]:mp){
			if(a%need_num==0){
				ans+=b;
			}
		}
		mp[gcd]++;
	}
	return ans; 	
}

/*
gcd=gcd(a,k)*gcd(b, k) ->multuple of k
a=(k/gcd);
b=(k/a);   a*b==k b will be multiple of a so that b*a will be multiple of k
*/