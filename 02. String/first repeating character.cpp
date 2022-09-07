https://practice.geeksforgeeks.org/problems/repeated-character2058/1

char firstRep (string s)
{
      for(int i=0;i<s.size();i++){
          if(count(s.begin(), s.end(), s[i])>1)
          return s[i];
      }
      return '#';
}