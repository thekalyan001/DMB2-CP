https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int temp=0,count=0;
        for(int i=0;i<n;i++){
            temp+=arr[i];
            //if(temp==0)count++;
            if(mp.find(temp)!=mp.end()){
                count+=mp[temp];
            }
            mp[temp]++;
        }
        return count;
    }