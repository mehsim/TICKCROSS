#include <iostream>
#include <conio.h>
#include"help.h"
#include <fstream>
using namespace std;

void printboard(int board[][3], int R)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 1)
				cout << "O ";
			else if (board[i][j] == 2)
				cout << "X ";
			else
				cout << "_ ";

		}
		cout << endl;
	}
}

bool checkwinner(int board[][3], int& who)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0)
		{
			who = board[i][0];
			return true;
		}
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0)
		{
			who = board[0][i];
			return true;
		}

	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
	{
		who = board[0][0];
		return true;
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != 0)
	{
		who = board[0][0];
		return true;
	}
	return false;
}
/*void findloc(int board[][3], int& row, int& col, int opp)
{
	bool winner = false;
	int who;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
			{
				row = i;
				col = j;
				board[i][j] = opp;
				winner = checkwinner(board, who);
				board[i][j] = 0;
				if (winner == true)
					break;
			}

		}
		if (winner == true)
			break;
	}
	if (winner == false)
	{
		if (board[1][1] == 0)
		{
			row = 1;
			col = 1;
		}
	}


}*/
int main()
{
	int board[3][3] = { 0 };
	int player = 1, row, col, who;
	bool winner = false;
	int x = 0, y = 0;
	gotoxy(x, y);
	printboard(board, 3);
	for (int i = 0; i < 9 && winner == false; i++)
	{
		char c = _getch();
		while (c != 13)
		{

			if (c == -32)
			{
				c = _getch();
				if (c == 'H')
				{
					if (y > 0)
					{
						y--;
						gotoxy(x, y);
					}
				}
				if (c == 'K')
				{
					if (x > 0)
					{
						x=x-2;
						gotoxy(x, y);
					}
				}
				if (c == 'M')
				{
					if (x < 4)
					{
						x=x+2;
						gotoxy(x, y);
					}
				}
				if (c == 'P')
				{
					if (y < 2)
					{
						y++;
						gotoxy(x, y);
					}
				}
				
			}
			else if (c == 'S')
			{
				ofstream fout("save.txt");
				fout << player << " " << i << " ";
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						fout << board[i][j];
					}
				}
				fout.close();
			}

			else if (c == 'L')
			{
				ifstream fin("save.txt");
				fin >> player >> i;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						fin >> board[i][j];
					}
				}
				gotoxy(0, 0);
				printboard(board, 3);
			}
			c = _getch();
		}
		row = y;
		col = x/2;
		if (player == 1)
		{
			board[row][col] = 1;
			player = 2;
		}
		else
		{
			board[row][col] = 2;
			player = 1;
		}
		gotoxy(0, 0);
		printboard(board, 3);
		winner = checkwinner(board, who);

	}
	if (winner == true)
		cout << "the winner is player" << who;
	else
		cout << "it is a draw";

	_getch();
	return 0;

}
