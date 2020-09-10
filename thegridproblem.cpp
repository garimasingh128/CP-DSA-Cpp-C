/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int> >& grid, vector<vector<bool> >& vis, int& ans, int z, int z_count)
{
	int n=grid.size(), m=grid[0].size();
	vis[i][j]=1;
	if(grid[i][j]==0)
	z++;
	if(grid[i][j]==2)
	{
		if(z==z_count)
		ans++;
		vis[i][j]=0;
		return;
	}
	if(i>=1 && !vis[i-1][j] && grid[i-1][j]!=-1)
	dfs(i-1,j,grid,vis,ans,z,z_count);
	if(i<=n-1 && !vis[i+1][j] && grid[i+1][j]!=-1)
	dfs(i+1,j,grid,vis,ans,z,z_count);
	if(j>=1 && !vis[i][j-1] && grid[i][j-1]!=-1)
	dfs(i,j-1,grid,vis,ans,z,z_count);
	if(j<m-1 && !vis[i][j+1] && grid[i][j+1]!=-1)
	dfs(i,j+1,grid,vis,ans,z,z_count);
	vis[i][j]=0;
}
int uni(vector<vector<int> >& grid)
{
	int z_count=0;
	int n=grid.size(),m=grid[0].size();
	int ans=0;
	vector<vector<bool> > vis(n, vector<bool>(m,0));
	int x,y;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(grid[i][j]==0)
			z_count++;
			else if(grid[i][j]==1)
			{
				x=i,y=j;

			}
		}
	}
	dfs(x,y,grid,vis,ans,0,z_count);
	return ans;
}
int main()
{
	vector<vector<int> > grid{ { 1,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,2,-1 } };
	cout<<uni(grid);
	return 0;
}
