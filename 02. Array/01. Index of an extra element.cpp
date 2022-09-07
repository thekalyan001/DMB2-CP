https://practice.geeksforgeeks.org/problems/index-of-an-extra-element/1#


logn--

int findExtra(int a[], int b[], int n) {
      int left=0, right=n-1, ans=n;
      while(left<=right){
          int mid=(left+right)/2;
          if(a[mid]==b[mid])
            left=mid+1;
          else
          {
              ans=mid;
              right=mid-1;
          }
      }
      return ans;
    }