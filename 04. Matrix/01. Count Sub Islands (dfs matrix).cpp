https://leetcode.com/problems/count-sub-islands/

void eraseIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int m, int n, bool &res){
        if(i>=m or i<0 or j>=n or j<0)
            return;
        
        if(grid1[i][j]==0 && grid2[i][j]==1) //if one cell in grid1 is 0 and grid2 is 1 then it's not a subisland
            res=false;
        
        if(grid2[i][j]==0)return;
        grid2[i][j]=0;
        
        eraseIsland(grid1,grid2, i+1, j, m, n, res);
        eraseIsland(grid1,grid2, i-1, j, m, n, res);
        eraseIsland(grid1,grid2, i, j+1, m, n, res);
        eraseIsland(grid1,grid2, i, j-1, m, n, res);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         int count=0, m=grid1.size();
        int n=m?grid1[0].size():0;
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    bool res=true;
                    eraseIsland(grid1,grid2, i, j, m, n, res); 
                    count+=res;
                }
            }
        }
        return count;
    }