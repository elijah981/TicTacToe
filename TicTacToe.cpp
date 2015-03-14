// My Tic-Tac-Toe playing bot
#include<stdio.h>

#define PLAYER 1
#define COMPUTER 2

int win(const int[9],int);
void display(int[9]);
void PlayerMove(int[9],int);
void ComputerMove(int[9],int);
char GetChar(int);
int minimax(int[9],int,int);
int max(int[9],int);
int min(int[9],int);

int main()
{
	int board[9]={0,0,0,0,0,0,0,0,0};
	int player = 1;
	
	printf("TICTACTOE Game:\nPlayer is 'X' and Computer is 'O'.\n\n");
	
	int turn=1;
	do{
        display(board);
        if(win(board,0) != 0)
			break;
			
		if((turn+player)%2 == 0)
		{
			//Player plays
			PlayerMove(board,PLAYER);
		}
		else
		{
			//Computer plays
			ComputerMove(board,COMPUTER);
		}
		turn++;
	}while(turn<=9);
	
	if(win(board,0) > 0)
		printf("\nYou win! Wow.. this is inconceivable!!");
	else if(win(board,0) < -0)
		printf("\nComputer wins! You loose.");
	else if(win(board,0) == 0)
		printf("\nDraw game.. This is drool.");

	return 0;
}

int win(const int board[9], int depth)
{
	int winner[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	
	int score=0;
	for(int i=0; i<8; i++)
	{
		if(board[winner[i][0]] != 0)
		{
			if(board[winner[i][0]] == board[winner[i][1]] && board[winner[i][0]] == board[winner[i][2]])
			{
				if(board[winner[i][0]]== PLAYER)
					score = 10 - depth;
				else
					score = depth - 10;
				break;
			}
		}
	}
	return score;
}

void display(int board[9])
{
     printf("\n-------------\n");
     printf(" %c | %c | %c \n", GetChar(board[0]),GetChar(board[1]),GetChar(board[2]));
     printf("---+---+---\n");
     printf(" %c | %c | %c \n", GetChar(board[3]),GetChar(board[4]),GetChar(board[5]));
     printf("---+---+---\n");
     printf(" %c | %c | %c \n", GetChar(board[6]),GetChar(board[7]),GetChar(board[8]));
     printf("-------------\n");

}

char GetChar(int x)
{
	if (x == PLAYER)
		return 'X';
	if (x == COMPUTER)
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
	int score[9]={0},move[9]={0},count=0;
	for(int i=0; i<9; i++)
	{
		if(board[i] == 0)
		{
			board[i] = player;
			score[count] = minimax(board, 3-player, 0);
			move[count++] = i;
			board[i] = 0;
		}
	}
	int index = min(score,count);
	printf("Computer plays %d.\n",move[index]+1);
	board[move[index]] = player;
}

int minimax(int board[9], int player, int depth)
{
	int i;
	if(win(board,depth) != 0) return win(board,depth);
	
	depth+=1;
	
	int score[9]={0},move[9]={0},count=0;
	
	for(i=0; i<9; i++)
	{
		if(board[i] == 0)
		{
			board[i] = player;
			score[count] = minimax(board, 3-player,depth);
			move[count++] = i;
			board[i] = 0;
		}
	}
	
	if(player == PLAYER)
		return score[max(score,count)];
	else
		return score[min(score,count)];
}

int max(int score[9],int count)
{
	int i, maxScore=score[0],index=0;
	for(i=1;i<count;i++)
	{
		if(score[i]>maxScore)
		{
			maxScore = score[i];
			index = i;
		}
	}
	return index;
}

int min(int score[9],int count)
{
	int i, minScore=score[0],index=0;
	for(i=1;i<count;i++)
	{
		if(score[i]<minScore)
		{
			minScore = score[i];
			index = i;
		}
	}
	return index;
}
