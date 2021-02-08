class Solution {
public:
    void dfs(int i,int j,vector<vector<char> > &grid)
    {
        if(i<0 or j<0 or i>=grid.size() or j>= grid[0].size() or grid[i][j]!='1')
            return;
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int i,j,c=0;
        for(i=0;i<grid.size();i++)
        {
            for(j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    c++;
                    dfs(i,j,grid);
                }
            }
        }
        return c;
    }
};
