https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

reomve all occourencess of part from s
s = "daabcbaabcbc", part = "abc"
"dab"


string removeOccurrences(string s, string part) {
	string temp=s;
	int n=s.size(), m=part.size(), i=0,j=0;
	for(i=0, j=0;i<n;i++){
		
		temp[j++]=s[i];
		
		if(j>=m && temp.substr(j-m, m)==part)
			j-=m;
		
		i++;
	}
	return temp.substr(0, j);
}