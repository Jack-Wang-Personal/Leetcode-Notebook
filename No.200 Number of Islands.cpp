class Solution {
public:
    int xl;
    int yl;
    void dfs(vector<vector<char>>& grid,int x,int y){
        grid[x][y]='0';
        if(x-1>=0 && grid[x-1][y]=='1') dfs(grid,x-1,y);
        if(x+1<xl && grid[x+1][y]=='1') dfs(grid,x+1,y);
        if(y-1>=0 && grid[x][y-1]=='1') dfs(grid,x,y-1);
        if(y+1<yl && grid[x][y+1]=='1') dfs(grid,x,y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        xl=grid.size();
        yl=grid[0].size();
        for(int i=0;i<xl;i++){
            for(int j=0;j<yl;j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }
};
