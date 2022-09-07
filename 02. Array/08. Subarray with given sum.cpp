 https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

 vector<int> subarraySum(int arr[], int n, long long s)
    {
        int l=0, sum=arr[0];
        for(int i=1;i<=n;i++){
            
            while(sum>s && l<i-1){
                sum-=arr[l]; l++;
            }
            if(sum==s){
                return {l+1, i};
            }
            
            if(i<n)sum+=arr[i];
        }
        return {-1};
    }