https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

#include<iostream>
using namespace std;
int main(){
	int n,k; cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];

	int currSum=arr[0], start=0, i=0;

	for(i=1;i<n;i++){
		while(currSum>k && start<i-1)
		{
			currSum=currSum-arr[start++];
		}
		if(currSum==k)
		{
			cout << "Sum found between indexes " << start
                 << " and " << i - 1;
                 return 1;
		}
		if(i<n)
			currSum+=arr[i];
	}
	return 0; 
}