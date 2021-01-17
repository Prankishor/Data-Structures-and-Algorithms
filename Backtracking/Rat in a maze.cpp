#include<bits/stdc++.h>
using namespace std;
int ans[5][5] = { {0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0},
	                  {0, 0, 0, 0, 0}
	              };
bool solveMazeUtil(int maze[5][5], int x, int y, int ans[5][5]);
void printAns(int ans[5][5])
{
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isSafe(int maze[5][5], int x, int y)
{
	if(x<5 && y<5 && maze[x][y]==1)
	{
		return true;
	}
	return false;
}

bool solveMaze(int maze[5][5], int ans[5][5])
{
	if(solveMazeUtil(maze, 0, 0, ans)==false)
	{
		cout<<"Not possible"<<endl;
		return false;
	}

	printAns(ans);
	return true;
}


bool solveMazeUtil(int maze[5][5], int x, int y, int ans[5][5])
{
	if(x==5-1 && y==5-1 && maze[x][y]==1)
	{
		ans[x][y]=1;
		return true;
	}

	if(isSafe(maze, x, y)==true)
	{
		ans[x][y]=1;

		if(solveMazeUtil(maze, x+1, y, ans)==true)
		{
			return true;
		}

		if(solveMazeUtil(maze, x, y+1, ans))
		{
			return true;
		}

		ans[x][y]=0;
		return false;
	}

	//if isSafe==false
	return false;
}


int main()
{
	int maze[5][5] = {{1, 0, 1, 0, 1},
	                  {1, 1, 1, 1, 1},
	                  {0, 1, 0, 1, 0},
	                  {1, 0, 0, 1, 1},
	                  {1, 1, 1, 0, 1}
	              };

	
	 solveMaze(maze, ans);
	 return 0;
}
