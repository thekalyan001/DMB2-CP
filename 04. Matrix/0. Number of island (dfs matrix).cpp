https://leetcode.com/problems/number-of-islands/

void eraseIsland(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i>=m or i<0 or j>=n or j<0 or grid[i][j]=='0')
            return;
        
        grid[i][j]='0';
        eraseIsland(grid, i+1, j, m, n);
        eraseIsland(grid, i-1, j, m, n);
        eraseIsland(grid, i, j+1, m, n);
        eraseIsland(grid, i, j-1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0, m=grid.size();
        int n=m?grid[0].size():0;
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    eraseIsland(grid, i, j, m, n);
                }
            }
        }
        return count;
    }


    //similar  https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
    