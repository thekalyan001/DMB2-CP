//https://leetcode.com/problems/largest-number/

Time-nlogn space O(n)
static bool compare(string &s1, string &s2){
    return s1+s2>s2+s1;    
}
string largestNumber(vector<int>& nums) {
    vector<string>ans;
    for(int i=0;i<nums.size();i++)
        ans.push_back(to_string(nums[i]));

    sort(ans.begin(), ans.end(), compare);
    string res;
    for(string i:ans)res+=i;
        while(res[0]=='0' && res.length()>0)
            res.erase(0,1);
        return res;
    }