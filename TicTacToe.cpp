// My Tic-Tac-Toe playing bot
#include<stdio.h>

int win(int[9]);
void display(int[9]);
void PlayerMove(int[9],int);
void ComputerMove(int[9],int);
char GetChar(int);

int main()
{
	int board[9]={0,0,0,0,0,0,0,0,0};
	
	printf("Choose player 1(X) or 2(O):");
	int player = 0;
	scanf("%d",&player);
	
	int turn=1;
	do{
        display(board);
        if(win(board) != 0)
			break;
			
		if((turn+player)%2 == 0)
		{
			//Player plays
			PlayerMove(board,player);
		}
		else
		{
			//Computer plays
			PlayerMove(board,3-player);
		}
		turn++;
	}while(turn!=9);
	
	if(win(board) == 10)
		printf("\nYou win! Wow.. this is inconceivable!!");
	else if(win(board) == -10)
		printf("\nComputer wins! You loose.");
	else if(win(board) == 0)
		printf("\nDraw game.. This is drool.");

	return 0;
}

int win(int board[9])
{
	int winner[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	
	int score=0;
	for(int i=0; i<9; i++)
	{
		if(board[winner[i][0]] != 0 && board[winner[i][0]] == board[winner[i][1]] && board[winner[i][0]] == board[winner[i][2]])
		{
			if(board[winner[i][0]]== 1)
				score = 10;
			else
				score = -10;
			break;
		}
	}
	return score;
}

void display(int board[9])
{
     
     printf(" %c | %c | %c \n", GetChar(board[0]),GetChar(board[1]),GetChar(board[2]));
     printf("---+---+---\n");
     printf(" %c | %c | %c \n", GetChar(board[3]),GetChar(board[4]),GetChar(board[5]));
     printf("---+---+---\n");
     printf(" %c | %c | %c \n", GetChar(board[6]),GetChar(board[7]),GetChar(board[8]));
}

char GetChar(int x)
{
	if (x == 1)
		return 'X';
	if (x == 2)
		return 'O';
	if (x == 0)
		return ' ';
}
void PlayerMove(int board[9], int player)
{
	int num;
	do{
		printf("\nPlayer %d\n",player);
		printf("Enter location [1..9]:");
		scanf("%d",&num);
	}
	while(board[num-1]!=0 || num<0 || num>9);
	board[num-1] = player;
}

void ComputerMove(int board[9], int player)
{
	int move = -1, Score = -2;
	int i;
	for(i=0; i<9; i++)
	{
		if(board[i] == 0)
		{
			board[i] = player;
			int tempScore = -minimax(board, player);
			if(tempScore > Score)
			{
				Score = tempScore;
				move = i;
			}
			board[i] = 0;
		}
	}
	board[move] = player;
}

void minimax(int board[9], int player)
{
	int move = -1, Score = -2;
	int i;
	for(i=0; i<9; i++)
	{
		if(board[i] == 0)
		{
			board[i] = player;
			int tempScore = -minimax(board, player);
			if(tempScore > Score)
			{
				Score = tempScore;
				move = i;
			}
		}
	}
}
