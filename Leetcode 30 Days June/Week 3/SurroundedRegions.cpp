class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>& board)
    {
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!='O')
            return;
        board[i][j]='$';
        dfs(i+1,j,n,m,board);
        dfs(i-1,j,n,m,board);
        dfs(i,j-1,n,m,board);
        dfs(i,j+1,n,m,board);
    }
    void solve(vector<vector<char>>& board) {


        if(board.size()==0)
            return;
        int i,j,n,m;
        n=board.size();
        m=board[0].size();
        for(i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(i,0,n,m,board);
            }
            if(board[i][m-1]=='O')
            {
                dfs(i,m-1,n,m,board);
            }
        }
        for(j=0;j<m;j++)
        {
            if(board[0][j]=='O')
                dfs(0,j,n,m,board);
            if(board[n-1][j]=='O')
                dfs(n-1,j,n,m,board);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='$')
                    board[i][j]='O';
            }
        }

    }
};
