https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

int findMaxSum(int *arr, int n) {
	   int incl=arr[0], excl=0, new_excl=0;
	   for(int i=1;i<n;i++){
	       new_excl=max(incl, excl);
	       incl=excl+arr[i];
	       excl=new_excl;
	   }
	   return max(incl ,excl);
	}