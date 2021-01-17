#include<bits/stdc++.h>
using namespace std;
#define N 8

bool isSafe(int board[][N], int x, int y){

//check for previous rows (vertically)
	for(int row=0; row<x; row++){
		if(board[row][y]==1)
		{
			return false;
		}
	}

	int row = x;
	int col = y;

	//check for left diagonal

	while(row>=0 && col>=0)
	{
		if(board[row][col]==1)
		{
			return false;
		}
		row--;
		col--;
	}

	//check for right diagonal

	row = x;
	col = y;

	while(row>=0 && col<N)
	{
		if(board[row][col]==1)
		{
			return false;
		}
		row--;
		col++;
	}

	return true;
}

bool solveNQ(int board[][N], int x)
{
	//if we have placed queen in all rows
	if(x>=N)
	{
		return true;
	}
    
    //else for the given row, check all its column where can we put the queen
	for(int col=0; col<N; col++)
	{
		//if we can put, put it
		if(isSafe(board, x, col)){
			board[x][col]=1;
            //and then call for next row
			if(solveNQ(board, x+1))
			{
				return true;
			}

			//If we come back here with false, that means the config of
			//queens is wrong.

			//so we have to change the current queen, make it 0
			board[x][col]=0; //backtracking

			//And then continue with the for loop for the next place/column
		}
	}

	//If no column left, return false
	return false;


}

int main()
{
	int board[N][N]={0};
	if(solveNQ(board, 0)==false)
	{
		cout<<"Not Possible"<<endl;
	}
	else
	{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}


	return 0;
}
