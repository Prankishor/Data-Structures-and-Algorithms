#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 9

//USE ll NOT int

bool isSafe(int grid[][N], int x, int y, int num)
{
	for(int row=0; row<=8; row++)
	{
		if(grid[x][y]==num)
		{
			return false;
		}
	}

	for(int col=0; col<=8; col++)
	{
		if(grid[x][y]==num)
		{
			return false;
		}
	}

	int startRow = x-x%3, startCol = y-y%3;

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(grid[i+startRow][j+startCol]==num)
			{
				return false;
			}
		}
	}
	return true; 
}

bool solveSuduko(int grid[][N], int x, int y)
{
	if(x==N-1 && y==N)
	{
		return true;
	}

	if(y==N)
	{
		x++;
		y=0;
	}

	if(grid[x][y]>0)
	{
		return solveSuduko(grid, x, y+1);
	}

	for(int num =1; num<=N; num++)
	{
		if(isSafe(grid, x, y, num))
		{
			grid[x][y]=num;

			if(solveSuduko(grid, x, y+1))
			{
				return true;
			}
		}

		grid[x][y]=0;
	}
	return false;


}	


void print(int grid[][N])
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	 int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
 
    if (solveSuduko(grid, 0, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;
 
    return 0;
}



