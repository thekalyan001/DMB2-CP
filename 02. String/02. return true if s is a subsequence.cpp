https://leetcode.com/problems/is-subsequence/

// return true if s is a subsequence of t

 bool isSubsequence(string s, string t) {
        int n=s.size(), m=t.size(), j=0;
        for(int i=0;i<m && j<n;i++){
            if(s[j]==t[i])j++;
        }
        return j==n;
    }