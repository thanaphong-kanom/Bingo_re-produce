#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "windows.h"
#include "time.h"

void gotoxy(short x, short y);

main (void)
{
	int maintable[7][6] = {0};
	int play = 0, col, row, temp, chk=1, full=1;
	int slot1, p1 = 9;
	int slot2, p2 = 8;
	
	//Set player coin
	printf("\t1.%c\t2.%c\t3.%c\t4.%c\t5.%c\t6.%c\n\n",1 ,2, 3, 4, 5, 6);
	while(1)
	{
		printf("Enter player 1 coin: ");
		scanf("%d",&p1);
		if(p1>0 && p1< 7)
			break;
	}
	while(1)
	{
		printf("Enter player 2 coin: ");
		scanf("%d",&p2);
		if(p2 != p1 && p2>0 && p2< 7)
			break;
	}
	
	//Start game
	while(1)
	{
		system("cls");
		// Show slot Player 1
		for(row=0;row<7;row++)
		{
			for(col=0;col<6;col++)
			{
				if(maintable[row][col] != 0)
					printf("\t%2c", maintable[row][col]);
				else
					printf("\t%2c",130);
			}
			printf("\n\n");
		}
		printf("\t 1\t 2\t 3\t 4\t 5\t 6\n\n");
		// Enter slot Player 1
		while(1)
		{
			printf("Enter Player 1 Slot: ");
			scanf("%d",&slot1);
			full = 1;
			if(maintable[0][slot1-1] == 0)
				full = 0;
			if(full==0 && slot1>0 && slot1<7)
				break;
		}
		// Check slot Player 1
		for(row=6;row>=0;row--)
		{
			if(maintable[row][slot1-1] == 0)
				{
					maintable[row][slot1-1] = p1;
					break;
				}	
		}
		// Check row win Player 1
		for(row=0;row<7;row++)
		{
			chk = 1;
			for(col=0;col<5;col++)
			{
				if(maintable[row][col] == p1 && maintable[row][col] == maintable[row][col+1])
				{
					chk++;
					if(chk == 4)
					{
						play = 1;
						break;
					}	
				}
			}
		}
		// Check col win Player 1
		for(col=0;col<6;col++)
		{
			chk = 1;
			for(row=0;row<7;row++)
			{
				if(maintable[row][col] == p1 && maintable[row][col] == maintable[row+1][col])
				{
					chk++;
					if(chk == 4)
					{
						play = 2;
						break;
					}	
				}
			}
		}
		// Check left win Player 1
		for(col=5;col>2;col--)
		{
			for(row=3;row<7;row++)
			{
				if(maintable[row][col] == p1 && 
				   maintable[row][col] == maintable[row+1][col-1]&& 
				   maintable[row+1][col-1] == maintable[row+2][col-2] &&
				   maintable[row+2][col-2] == maintable[row+3][col-3])
				{
					play = 3;
					break;
				}
				
			}
		}
		// Check right win Player 1
		for(col=5;col>2;col--)
		{
			for(row=6;row>2;row--)
			{
				if(maintable[row][col] == p1 && 
				   maintable[row][col] == maintable[row-1][col-1]&& 
				   maintable[row-1][col-1] == maintable[row-2][col-2] &&
				   maintable[row-2][col-2] == maintable[row-3][col-3])
				{
					play = 4;
					break;
				}
				
			}
		}
		//Player 1 win
		if(play!=0)
			break;
		
		system("cls");
		
		// Show slot Player 2
		for(row=0;row<7;row++)
		{
			for(col=0;col<6;col++)
			{
				if(maintable[row][col] != 0)
					printf("\t%2c", maintable[row][col]);
				else
					printf("\t%2c",130);
			}
			printf("\n\n");
		}
		printf("\t 1\t 2\t 3\t 4\t 5\t 6\n\n");
		// Enter slot Player 2
		while(1)
		{
			printf("Enter Player 2 Slot: ");
			scanf("%d",&slot2);
			full = 1;
			if(maintable[0][slot2-1] == 0)
				full = 0;
			if(full==0 && slot2>0 && slot2<7)
				break;
		}
		// Check slot Player 2
		for(row=6;row>=0;row--)
		{
			if(maintable[row][slot2-1] == 0)
				{
					maintable[row][slot2-1] = p2;
					break;
				}	
		}
		// Check row win Player 2
		for(row=0;row<7;row++)
		{
			chk = 1;
			for(col=0;col<5;col++)
			{
				if(maintable[row][col] == p2 && maintable[row][col] == maintable[row][col+1])
				{
					chk++;
					if(chk == 4)
					{
						play = 5;
						break;
					}	
				}
			}
		}
		// Check col win Player 2
		for(col=0;col<6;col++)
		{
			chk = 1;
			for(row=0;row<6;row++)
			{
				if(maintable[row][col] == p2 && maintable[row][col] == maintable[row+1][col])
				{
					chk++;
					if(chk == 4)
					{
						play = 6;
						break;
					}	
				}
			}
		}
		// Check left win Player 2
		for(col=5;col>2;col--)
		{
			for(row=3;row<7;row++)
			{
				if(maintable[row][col] == p2 && 
				   maintable[row][col] == maintable[row+1][col-1]&& 
				   maintable[row+1][col-1] == maintable[row+2][col-2] &&
				   maintable[row+2][col-2] == maintable[row+3][col-3])
				{
					play = 7;
					break;
				}
				
			}
		}
		// Check right win Player 2
		for(col=5;col>2;col--)
		{
			for(row=6;row>2;row--)
			{
				if(maintable[row][col] == p2 && 
				   maintable[row][col] == maintable[row-1][col-1]&& 
				   maintable[row-1][col-1] == maintable[row-2][col-2] &&
				   maintable[row-2][col-2] == maintable[row-3][col-3])
				{
					play = 8;
					break;
				}
				
			}
		}
		//Player 2 win
		if(play!=0)
			break;
	}
	
	system("cls");
	
	//Show Game result
	for(row=0;row<7;row++)
	{
		for(col=0;col<6;col++)
		{
			if(maintable[row][col] != 0)
				printf("\t%2c", maintable[row][col]);
			else
				printf("\t%2c",130);
		}
		printf("\n\n");
	}
	printf("\t 1\t 2\t 3\t 4\t 5\t 6\n\n");
	//Game check
	if(play == 1)
		printf("player 1 win with row");
	else if(play == 2)
		printf("player 1 win with col");
	else if(play == 3)
		printf("player 1 win with left");
	else if(play == 4)
		printf("player 1 win with right");
	else if(play == 5)
		printf("player 2 win with row");
	else if(play == 6)
		printf("player 2 win with col");
	else if(play == 7)
		printf("player 2 win with left");
	else if(play == 8)
		printf("player 2 win with right");
	else
		printf("ERROR");
	
	return 0;
}

//definition of gotoxy function
void gotoxy(short x, short y)                                                      
{
	COORD pos ={x,y};
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
