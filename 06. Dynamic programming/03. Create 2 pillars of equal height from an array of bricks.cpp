#include <iostream>
#include<vector>
using namespace std;
void solve(vector<int>arr, int p1, int p2, int n, int &ans){
  if(p1 == p2){
    if(p1 > ans){
      ans = p1;
    }
  }

  if(n==0) return;
  solve(arr,  p1, p2, n-1, ans);
  solve(arr,  p1+arr[n-1], p2, n-1, ans);
  solve(arr, p1, p2+arr[n-1], n-1, ans);
}
int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0 ; i<n ; ++i){
    cin>>arr[i];
  }
  int ans = -1;
  solve(arr,0,0,n,ans);

  cout<<ans;
  return 0;
}


/*  -------- Problem Statement ----------

There are N bricks (a1, a2, ...., aN). Each brick has length L1, L2, ...., LN). Make 2 highest parallel pillars (same length pillars) using the bricks provided.

Constraints:

There are N bricks. 5<=N<=50
Length of each brick. 1<=L<=1000
Sum of the bricks lengths <= 1000
Length of the bricks is not given in size order. There may be multiple bricks which may have the same length. Not all bricks have to be used to create the pillars.

Example:

1st Example-

N = 5
2, 3, 4, 1, 6

Possible Sets:
(2, 6) and (3, 4, 1)

Answer: 8
*/