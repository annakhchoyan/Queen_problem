#include <iostream>

const int n = 8;

void printSolution(int board[n][n])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << " " << board[i][j] << " ";
		}
		
		std::cout << std::endl;
	}
}

bool isSafe(int board[n][n], int row, int col)
{
	int i;
	int j;

	for (i = 0; i < col; ++i)
	{
		if (board[row][i])
		{
			return false;
		}
	}
	for (i = row, j = col; i >= 0 && j >= 0; --i, --j)
	{
		if (board[i][j])
		{
			return false;
		}
	}
	for (i = row, j = col; j >= 0 && i < n; ++i, --j)
	{
		if (board[i][j])
		{
			return false;
		}
	}
	
	return true;
}

bool solveNQUtil(int board[n][n], int col)
{
	if (col >= n)
	{
		return true;
	}
	for (int i = 0; i < n; ++i)
	{
		if (isSafe(board, i, col))
		{
			board[i][col] = 1;
			
			if (solveNQUtil(board, col + 1))
			{
				return true;
			}
			
			board[i][col] = 0;
		}
	}
	
	return false;
}

bool solveNQ()
{
	int board[n][n] = { {0, 0, 0, 0},
	       		    {0, 0, 0, 0},
			    {0, 0, 0, 0},
	           	    {0, 0, 0, 0} };
	
	if (solveNQUtil(board, 0) == false)
	{
		std::cout << "Solution does not exist";
	
		return false;
	}

	printSolution(board);
	
	return true;
}

int main()
{
	solveNQ();

	return 0;
}
