/*
Lab 10
Justin Varga
CSE 130-01
4/9/2021
Description:
	Simulate a 3D tic-tac-toe game using C++ to utilize OOD.
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

/* Board Class*/
class Board
{
	protected:
		char cells[3][3];
		
	public:
		Board()
		{
			for (int r = 0; r < 3; r++)
			{ 
				for (int c = 0; c < 3; c++) 
				{
					fillCell(r, c, ' ');
				}
			}
		}
		
		char getMark(int row, int col)
		{
			return cells[row][col];
		}
		
		void fillCell(int row, int col, char mark)
		{
			cells[row][col] = mark;
		}
		
		bool isFree(int row, int col)
		{
			return getMark(row, col) == ' ';
		}
		
		int getNumFreeCells()
		{
			int numFreeCells = 0;
			
			for (int row = 0; row < 3; row++)
			{
				for  (int col = 0; col < 3; col++)
				{
					if (this->isFree(row, col))
					{
						numFreeCells++;
					}
				}
			}
			
			return numFreeCells;
		}
		
		virtual void printBoard()
		{
			cout << "\n " << getMark(0, 0) << " | " << getMark(0, 1) << " | " << getMark(0, 2) << "\n---+---+---"
			     << "\n " << getMark(1, 0) << " | " << getMark(1, 1) << " | " << getMark(1, 2) << "\n---+---+---"
			     << "\n " << getMark(2, 0) << " | " << getMark(2, 1) << " | " << getMark(2, 2) << "\n" << endl;	
		}
		
		virtual void printBoard(bool isMarked)
		{
			if (!isMarked) return printBoard();
			
			cout << "       -----------"
				     << "\n Row 0: " << getMark(0,0) << " | " << getMark(0,1) << " | " << getMark(0,2) << "\n       ---+---+---" 
				     << "\n Row 1: " << getMark(1,0) << " | " << getMark(1,1) << " | " << getMark(1,2) << "\n       ---+---+---"
				     << "\n Row 2: " << getMark(2,0) << " | " << getMark(2,1) << " | " << getMark(2,2)
				     << "\n       -----------\nColumn: 0 | 1 | 2" 
				     << "\n\nPlease input the row, then column you wish to fill (ex. " << rand() % 2 << " " << rand() % 2 << "): " << endl;
		}
};

/* Extended Class Board */
class Board3D : public Board
{
	protected:
		int boardPos;
	
	public:
		Board3D(int pos)
		{
			boardPos = pos;
			
			for (int r = 0; r < 3; r++)
			{ 
				for (int c = 0; c < 3; c++) 
				{
					fillCell(r, c, ' ');
				}
			}
		}
		
		int getPos() { return boardPos; }
		
		void printBoard()
		{		
			/*====================================                  	 
			
			      .-----------.
			     / A / B / C /|
			    /---/---/---/ :
			   / D / E / F /      Position 0
		          /---/---/---/     
		 	 / G / H / I /       
			{-----------{
			|           |
			:           :
			
			      :           :
			      |           |
			      ;-----------|
			     , A / B / C /|
			    ,---/---/---/ :
			   , D / E / F /      Position 1
			: ,---/---/-:-/
			|, G / H / I|/
			|-----------|
			|           |
			:           :
		
			      :           :
			      |           |
			      ;-----------;
			     , A / B / C /
			    ,---/---/---/ 
			   , D / E / F /      Position 2
			: ,---/---/-:-/      
			|, G / H / I|/        
			'-----------'          
			  
			====================================*/
			
			string strs[3] = 
			{
				string("\n      .-----------.\n     / A / B / C /|\n    /---/---/---/ :\n   / D / E / F /\n  /---/---/---/\n / G / H / I /\n{-----------{\n|           |\n:           :\n"),
				string("\n      :           :\n      |           |\n      ;-----------|\n     , A / B / C /|\n    ,---/---/---/ :\n   , D / E / F /\n: ,---/---/-:-/\n|, G / H / I|/\n|-----------|\n|           |\n:           :\n"),
				string("\n      :           :\n      |           |\n      ;-----------;\n     , A / B / C /\n    ,---/---/---/\n   , D / E / F /\n: ,---/---/-:-/\n|, G / H / I|/\n\'-----------\'\n")
			};
			
			string posStr("");
			
			posStr.assign(strs[getPos()]);
			
			for (int row = 0; row < 3; row++)
			{
				for (int col = 0; col < 3; col++)
				{
					int d = 3 * row + col;	// 0 <= d <= 8
					char c = 'A' + d;	// A <= c <= I
					
					int found = posStr.find_first_of(c);
					
					if (found <= 0 || found > posStr.length()) continue;
					
					posStr.replace(found, 1, 1, getMark(row, col));
				}
			}
			
			cout << posStr << endl;
		}
		
		void printBoard(bool isMarked)
		{		
			/*====================================             
			
			      .-----------.			      .--------------.
			     / A / B / C /|			     / A0 / B0 / C0 /|
			    /---/---/---/ :			    /----/----/----/ :
			   / D / E / F /			   / D0 / E0 / F0 /
		          /---/---/---/				  /----/----/----/
		 	 / G / H / I /				 / G0 / H0 / I0 /
			{-----------{				{--------------{
			|           |				|              |
			:           :				:              :
			
			      :           :			      :              :
			      |           |			      |              |
			      ;-----------|			      ;--------------|
			     , A / B / C /|			     , A1 / B1 / C1 /|
			    ,---/---/---/ :			    ,----/----/----/ :
			   , D / E / F /			   , D1 / E1 / F1 /	
			: ,---/---/-:-/				: ,----/----/--:-/
			|, G / H / I|/				|, G1 / H1 / I1|/
			|-----------|				|--------------|
			|           |				|              |
			:           :				:              :
		
			      :           :			      :              :
			      |           |			      |              |
			      ;-----------;			      ;--------------;
			     , A / B / C /			     , A2 / B2 / C2 /
			    ,---/---/---/			    ,----/----/----/
			   , D / E / F /			   , D2 / E2 / F2 /
			: ,---/---/-:-/				: ,----/----/--:-/
			|, G / H / I|/				|, G2 / H2 / I2|/
			'-----------'				'--------------'
			
			====================================*/
			
			if (!isMarked) 
			{
				return printBoard();
			}
			
			string strs[3] =
			{
				string("\n      .-----------.\t\t\t      .--------------.\n     / A / B / C /|\t\t\t     / A0 / B0 / C0 /|\n    /---/---/---/ :\t\t\t    /----/----/----/ :\n   / D / E / F /\t\t\t   / D0 / E0 / F0 /\n  /---/---/---/\t\t\t\t  /----/----/----/\n / G / H / I /\t\t\t\t / G0 / H0 / I0 /\n{-----------{\t\t\t\t{--------------{\n|           |\t\t\t\t|              |\n:           :\t\t\t\t:              :\n"),
				string("\n      :           :\t\t\t      :              :\n      |           |\t\t\t      |              |\n      ;-----------|\t\t\t      ;--------------|\n     , A / B / C /|\t\t\t     , A1 / B1 / C1 /|\n    ,---/---/---/ :\t\t\t    ,----/----/----/ :\n   , D / E / F /\t\t\t   , D1 / E1 / F1 /\n: ,---/---/-:-/\t\t\t\t: ,----/----/--:-/\n|, G / H / I|/\t\t\t\t|, G1 / H1 / I1|/\n|-----------|\t\t\t\t|--------------|\n|           |\t\t\t\t|              |\n:           :\t\t\t\t:              :\n"),
				string("\n      :           :\t\t\t      :              :\n      |           |\t\t\t      |              |\n      ;-----------;\t\t\t      ;--------------;\n     , A / B / C /\t\t\t     , A2 / B2 / C2 /\n    ,---/---/---/\t\t\t    ,----/----/----/\n   , D / E / F /\t\t\t   , D2 / E2 / F2 /\n: ,---/---/-:-/\t\t\t\t: ,----/----/--:-/\n|, G / H / I|/\t\t\t\t|, G2 / H2 / I2|/\n'-----------'\t\t\t\t'--------------'\n")
			};
			
			string posStr("");
			
			posStr.assign(strs[getPos()]);
			
			for (int row = 0; row < 3; row++)
			{
				for (int col = 0; col < 3; col++)
				{
					int d = 3 * row + col;		// 0 <= d <= 8
					char c = 'A' + d;		// A <= c <= I
					
					int found = posStr.find_first_of(c);
					
					if (found <= 0 || found > posStr.length()) continue;
					
					posStr.replace(found, 1, 1, getMark(row, col));
				}
			}
			
			cout << posStr << endl;	
		}	
};

/* Player Class */
class Player
{
	protected:
		string name;
		char mark;
		int score;
		
		void setName(string name)
		{
			this->name = name;
		}
		
		void setMark(char mark)
		{
			this->mark = mark;
		}
	
	public:
		Player()
		{
			setName("");
			setMark(' ');
			setScore(0);
		}
		
		Player(char mark)
		{
			string name;
			
			cout << "Please enter the player's name: " << endl;
			cin >> name;
			
			while ((getchar()) != '\n');
			
			setName(name);
			setMark(mark);
			setScore(0);
		}
		
		Player(string name, char mark)
		{
			setName(name);
			setMark(mark);	
			score = 0;
		}
		
		char getMark()
		{
			return mark;
		}
		
		string getName()
		{
			return name;
		}
		
		int getScore()
		{
			return score;
		}
		
		virtual void play(Board *b)
		{
			int row, col;
			
			while(true)
			{
				cout << "       -----------"
				     << "\n Row 0: " << b->getMark(0,0) << " | " << b->getMark(0,1) << " | " << b->getMark(0,2) << "\n       ---+---+---" 
				     << "\n Row 1: " << b->getMark(1,0) << " | " << b->getMark(1,1) << " | " << b->getMark(1,2) << "\n       ---+---+---"
				     << "\n Row 2: " << b->getMark(2,0) << " | " << b->getMark(2,1) << " | " << b->getMark(2,2)
				     << "\n       -----------\nColumn: 0 | 1 | 2" 
				     << "\n\nPlease input the row, then column you wish to fill (ex. " << rand() % 2 << " " << rand() % 2 << "): " << endl;
				     
				cin >> row >> col;
				
				while ((getchar()) != '\n');
				
				if (b->isFree(row, col))
				{
					b->fillCell(row, col, mark);
					break;
				}
				else
				{
					cout << "\nYou can not play there! Please choose an empty one!" << endl;
				}
			}
		}
		
		void setScore(int pts)
		{
			score = pts;
		}
		
		void addScore()
		{
			score += 1;
		}
		
		void addScore(int pts)
		{
			score += pts;
		}
};

/* CPU Player */
class CPUPlayer : public Player
{
	public:
		CPUPlayer()
		{
			setName("CPU");
			setMark(' ');
			setScore(0);
		}
		
		CPUPlayer(char mark)
		{	
			setName("CPU");
			setMark(mark);
			setScore(0);
		}
		
		CPUPlayer(string name, char mark)
		{
			setName("CPU");
			setMark(mark);	
			setScore(0);
		}
		
		virtual void play(Board *b)
		{
			int rrow, rcol;
			
			do
			{
				rrow = rand() % 3;
				rcol = rand() % 3;	
			}
			while(!b->isFree(rrow, rcol));
			
			b->fillCell(rrow, rcol, mark);
		}
		
		virtual void play3D(Board3D *b[])
		{
			int rbrd, rrow, rcol;
			
			do
			{
				rbrd = rand() % 3;
				rrow = rand() % 3;
				rcol = rand() % 3;	
			}
			while(!b[rbrd]->isFree(rrow, rcol));
			
			b[rbrd]->fillCell(rrow, rcol, mark);
		}
};

/* TicTacToe Class */
class TTT
{
	protected:
		Player *players[2];
		Board *gameBoard;
		
		int scores[2];
		
		int turn;
	
	public:
		TTT()
		{	
			// This is bad but necessary
		}
		
		TTT(Player *p1, Player *p2, Board *b)
		{	
			players[0] = p1;
			players[1] = p2;
			
			gameBoard = b;
			
			assert(players[0] != NULL && players[1] != NULL && gameBoard != NULL);
			
			updateScores();
			
			turn = 0;
		}
		
		void updateScores()
		{
			for(int i = 0; i < 2; i++)
			{
				scores[i] = players[i]->getScore();
			}
		}
		
		virtual void tallyWins()
		{
			char mark;
			char p1Mark = players[0]->getMark();
			char p2Mark = players[1]->getMark();
			int tempScore1 = 0;
			int tempScore2 = 0;
			
			// Diagonals
			mark = gameBoard->getMark(1,1);
			
			if ((mark == gameBoard->getMark(0,0) && mark == gameBoard->getMark(2,2)) || (mark == gameBoard->getMark(0,2) && mark == gameBoard->getMark(2,0)))
			{
				if (mark == p1Mark)
				{
					tempScore1++;
				}
				else if (mark == p2Mark)
				{
					tempScore2++;
				}
			}
			
			// Rows
			for (int r = 0; r < 3; r++)
			{
				mark = gameBoard->getMark(r,0);
				if (mark == gameBoard->getMark(r,1) && mark == gameBoard->getMark(r,2))
				{
					if (mark == p1Mark)
					{
						tempScore1++;
					}
					else if (mark == p2Mark)
					{
						tempScore2++;
					}
				}
			}
			
			// Columns
			for (int c = 0; c < 3; c++)
			{
				mark = gameBoard->getMark(0,c);
				if (mark == gameBoard->getMark(1,c) && mark == gameBoard->getMark(2,c))
				{
					if (mark == p1Mark)
					{
						tempScore1++;
					}
					else if (mark == p2Mark)
					{
						tempScore2++;
					}
				}
			}
			
			players[0]->setScore(tempScore1);
			players[1]->setScore(tempScore2);
			
			updateScores();
		}
		
		Player* findVictor()
		{
			if (players[0]->getScore() > players[1]->getScore())
			{
				return players[0];
			}
			else if (players[1]->getScore() > players[0]->getScore())
			{
				return players[1];
			}
			else
			{
				return NULL;
			}
		}
		
		virtual void doTurn()
		{
			
		}
};

/* Extension Class */
class TTT3D : public TTT
{
	protected:
		Board3D *gameBoard
			// Did it again
		}
		Board3D *boards[3];
		
	public:
		TTT3D()
		{}
		
		TTT3D(Player *p1, Player *p2)
		{	
			players[0] = p1;
			players[1] = p2;
			
			gameBoard = (Board3D*)calloc(3, sizeof(Board3D));
			boards[0] = &gameBoard[0];
			boards[1] = &gameBoard[1];
			boards[2] = &gameBoard[2];
			
			assert(players[0] != NULL && players[1] != NULL && gameBoard != NULL);
			
			updateScores();
			
			turn = 0;
		}
		
		void tallyWins()
		{
			char mark;
			char p1Mark = players[0]->getMark();
			char p2Mark = players[1]->getMark();
			int tempScore1 = 0;
			int tempScore2 = 0;
			
			for (int b = 0; b < 3; b++)
			{
				
				// Diagonals
				mark = gameBoard[b].getMark(1,1);
				
				if ((mark == gameBoard[b].getMark(0,0) && mark == gameBoard[b].getMark(2,2)) || (mark == gameBoard[b].getMark(0,2) && mark == gameBoard[b].getMark(2,0)))
				{
					if (mark == p1Mark)
					{
						tempScore1++;
					}
					else if (mark == p2Mark)
					{
						tempScore2++;
					}
				}
				
				// Rows
				for (int r = 0; r < 3; r++)
				{
					mark = gameBoard[b].getMark(r,0);
					if (mark == gameBoard[b].getMark(r,1) && mark == gameBoard[b].getMark(r,2))
					{
						if (mark == p1Mark)
						{
							tempScore1++;
						}
						else if (mark == p2Mark)
						{
							tempScore2++;
						}
					}
				}
				
				// Columns
				for (int c = 0; c < 3; c++)
				{
					mark = gameBoard[b].getMark(0,c);
					if (mark == gameBoard[b].getMark(1,c) && mark == gameBoard[b].getMark(2,c))
					{
						if (mark == p1Mark)
						{
							tempScore1++;
						}
						else if (mark == p2Mark)
						{
							tempScore2++;
						}
					}
				}
			}
			
			// 3Ds Row
			for (int r = 0; r < 3; r++)
			{
				for (int c = 0; c < 3; c++)
				{
					mark = gameBoard[0].getMark(r,c);
				
					if (mark == gameBoard[1].getMark(r,c) && mark == gameBoard[2].getMark(r,c))
					{
						if (mark == p1Mark)
						{
							tempScore1++;
						}
						else if (mark == p2Mark)
						{
							tempScore2++;
						}
					}	
				}
			}
			
			
			players[0]->setScore(tempScore1);
			players[1]->setScore(tempScore2);
			
			updateScores();
		}
};


/* Main Function */
int main()
{	
	// Initialize variables	
	Player you;
	CPUPlayer cpu;
	
	TTT3D game;
	
	int r, turn;
	
	// Choose whether CPU is first
	srand(time(NULL));
	
	r = rand() % 2;
	
	if (r == 0) // CPU first
	{
		cpu = CPUPlayer("CPU", 'O');
		you = Player('X');
		
		game = TTT3D(&cpu, &you);
	}
	else // You first
	{
		cpu = CPUPlayer("CPU", 'X');
		you = Player('O');
		
		game = TTT3D(&you, &cpu);
	}
	
	// Simulate Game
	for (turn = 0; turn < 27; turn++) // There will be at most 27 turns
	{	
		b.printBoard();
		
		for (int j = 0; j < 3; j++)
		{
			char c = p->getMark();
			if (c == b.checkForWin())
			{
				p->win();
				victor = p;
				break;
			}
		}
		
		//delete(p);
	}
	
	// Check if there is a draw
	if (b.getNumFreeCells() == 0)
	{
		cout << "There was a draw!" << endl;
	}
	
	// Exit program
	system("pause");
}
