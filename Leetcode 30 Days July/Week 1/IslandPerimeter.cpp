class Solution {
public:
    int DFS(vector<vector<int>>& grid,int x, int y,vector<vector<bool>>&visited){

        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||!grid[x][y])
            return 1;
        if(visited[x][y])
            return 0;

        visited[x][y] = true;

        int a = DFS(grid,x+1,y,visited);
            a +=DFS(grid,x-1,y,visited);
            a +=DFS(grid,x,y+1,visited);
            a +=DFS(grid,x,y-1,visited);

        return a;
    }
    int islandPerimeter(vector<vector<int>>& grid) {

        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));

        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[i].size();j++)
            {
                if(grid[i][j])
                {
                    return DFS(grid,i,j,visited);
                }
            }
        }
        return 0;
    }
};
