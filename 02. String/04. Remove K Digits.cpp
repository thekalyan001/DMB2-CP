 https://leetcode.com/problems/remove-k-digits/description/

 Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.



string removeKdigits(string num, int k) {
       string ans="";
       ans.push_back(num[0]);int n=num.length();
       for(int i=1;i<n;i++){
           while(k && ans.back()>num[i]){
               k--; ans.pop_back();
           }
           ans.push_back(num[i]);
       }

       // remove k digit
       while(k && !ans.empty()){
           k--; ans.pop_back();
       }
       //at end if there is leading 0
       if(ans[0]=='0' && ans.length()>1){
           reverse(ans.begin(), ans.end());
           while(ans.back()=='0')ans.pop_back();
           reverse(ans.begin(), ans.end());
       }
       return ans==""?"0":ans;
    }